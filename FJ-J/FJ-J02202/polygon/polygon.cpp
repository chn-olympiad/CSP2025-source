#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long c[6001][6001], a[10001], n, ans, cnt, maxn;

void init() {
	c[0][0] = 1;
	for (int i = 1; i < 5500; i++) {
		for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	init();
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	if (n < 4) {
		for (int i = 1; i <= n; i++) {
			cnt += a[i];
			maxn = max(maxn, a[i]);
		}
		if (maxn * 2 < cnt) cout << 1;
		else cout << 0;
		return 0;
	} else {
		for (int i = 1; i <= n; i++) maxn = max(maxn, a[i]);
		if (maxn == 1) {
			for (int i = 3; i <= n; i++) ans = (ans + c[n + 1][i + 1]) % mod;
			printf("%lld", ans % mod);
		} else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (abs(j - i) > 2) {
						cnt = maxn = 0;
						for (int k = min(i, j); k <= max(i, j); k++) {
							cnt += a[k];
							maxn = max(maxn, a[k]);
						}
						if (cnt > maxn * 2) {
							ans++;
							ans %= mod;
						}
					}
				}
			}
			printf("%lld", ans % mod);
		}
		return 0;
	}
	return 0;
}
