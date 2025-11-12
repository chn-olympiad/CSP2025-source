// GZ-S00280 贵阳市第一实验中学 林钰涵
#include <bits/stdc++.h>
using namespace std;

int n, m, ans, a[505], p[505];
char s[505];

inline void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[i] = i;
	}
	do {
		int num = 0;
		for (int i = 1; i <= n; i++) {
			if (num >= a[p[i]] || s[i] == '0') ++num;
		}
		if (n - num >= m) ++ans;
	} while (next_permutation(p + 1, p + n + 1));
	printf("%d\n", ans);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
}
