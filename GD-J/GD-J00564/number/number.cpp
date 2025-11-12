#include <stdio.h>
char inputString[1145141];
int buckets[114];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", inputString);
	int i;
	for(i = 0; inputString[i] != '\0'; i += 1) {
		if(inputString[i] <= '9' && inputString[i] >= '0') {
			buckets[inputString[i] - '0'] += 1;
		}
	}
	for(i = 9; i >= 0; i -= 1) {
		while(buckets[i] > 0) {
			printf("%d", i);
			buckets[i] -= 1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
