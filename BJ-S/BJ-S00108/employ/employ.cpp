#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500, MOD = 998244353;
int n, m, c[MAXN + 5], ans;
int dp[(1 << 20) + 5][20 + 5];
bool s[MAXN + 5];
char S[MAXN + 5];
inline void addm(int &x, int d) {
	x = (0LL + x + d + MOD) % MOD;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, S + 1);
	for (int i = 1; i <= n; i ++) scanf("%d", c + i);
	for (int i = 1; i <= n; i ++) s[i] = S[i] - '0';
	if (m == n) {
		for (int i = 1; i <= n; i ++)
			if (! s[i]) {
				puts("0");
				return 0 ;
			}
		for (int i = 1; i <= n; i ++)
			if (c[i] == 0) {
				puts("0");
				return 0;
			}
		ans = 1;
		for (int i = 1; i <= n; i ++)
			ans = 1LL * ans * i % MOD;
		printf("%d\n", ans);
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i ++) {
		int d = __builtin_popcount(i);
		for (int j = 0; j <= d; j ++) {
			for (int k = 1; k <= n; k ++) {
				if (i >> (k - 1) & 1) continue;
				if (j >= c[k]) addm(dp[i | (1 << (k - 1))][j + 1], dp[i][j]);
				else addm(dp[i | (1 << (k - 1))][j + (s[d + 1] ^ 1)], dp[i][j]);
			}
		}
	}
	for (int i = 0; i <= n - m; i ++) addm(ans, dp[(1 << n) - 1][i]);
	printf("%d\n", ans);
	return 0;
}
