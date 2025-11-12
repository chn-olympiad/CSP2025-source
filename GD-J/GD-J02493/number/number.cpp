#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
char a[N];
int b[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", a + 1);
	int len = strlen(a + 1);
	for (int i = 1; i <= len; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			int x = a[i] - '0';
			b[x]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (b[i]--) {
			printf("%d", i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
