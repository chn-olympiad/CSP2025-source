#include <stdio.h>
int a[10];
char in;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while ((in = getchar()) != EOF)  if (in >= '0' && in <= '9') a[in - '0']++;
	
	for (int i = 9; i >= 0; i--) {
		int cnt = a[i];
		while (cnt) {
			cnt--;
			putchar(i + '0');
		}
	}
	return 0;
}
