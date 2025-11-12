#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char str[N];
int n, cnt[20];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cnt[str[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i]) {
			cnt[i]--;
			printf("%d", i);
		}
	}
	return 0;
}
