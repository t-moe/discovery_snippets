#include "stm32f4_discovery.h"
#include <stdbool.h>

volatile unsigned int tickleft;

void SysTick_Handler(void) {
	--tickleft;
}

void delay(unsigned int ms) {
	tickleft=ms;
	while(tickleft);
}


int main(void) {
	int state=0;

	SysTick_Config(SystemCoreClock/1000);

	STM_EVAL_LEDInit(LED3);
	STM_EVAL_LEDInit(LED4);
	STM_EVAL_LEDInit(LED5);
	STM_EVAL_LEDInit(LED6);

	STM_EVAL_LEDOff(LED3);
	STM_EVAL_LEDOff(LED4);
	STM_EVAL_LEDOff(LED5);
	STM_EVAL_LEDOff(LED6);
	
	while(1) {	


		delay(500);
		state++;
		state%=4;
		
		switch(state) {
			case 0:
				STM_EVAL_LEDOff(LED6);
				STM_EVAL_LEDOn(LED3);
			break;
			case 1:
				STM_EVAL_LEDOff(LED3);
				STM_EVAL_LEDOn(LED4);
			break;
			case 2:
				STM_EVAL_LEDOff(LED4);
				STM_EVAL_LEDOn(LED5);
			break;
			case 3:
				STM_EVAL_LEDOff(LED5);
				STM_EVAL_LEDOn(LED6);
			break;

		}		
	}
}
