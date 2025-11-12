#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 2;
char s[N];
int lens, cnt[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	lens = strlen(s + 1);
	for (int i = 1; i <= lens; i++) {
		if (isdigit(s[i])) {
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}

