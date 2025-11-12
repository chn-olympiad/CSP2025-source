#include <stdio.h>
#include <ctype.h>
char s[2000001];
int n, mr[10], mrl;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	for (; s[n]; ++n) {
		if (isdigit(s[n])) {
			++mr[s[n] ^ 48];
		}
	}
	for (int i = 9; ~i; --i) {
		if (mr[i]) {
			for (int j = 0; j < mr[i]; ++j) {
				putchar(i + 48);
			}
		}
	}
}
