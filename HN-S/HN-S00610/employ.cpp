#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
string s;
int n, m, ans, fac[505], cnt[505], c[505][505], dp[2][505][505];
int Sum(int x, int y) {
	return (x += y) >= mod ? (x - mod) : x;
}
void add(int &x, int v) {
	(x += v) >= mod ? (x -= mod) : 0;
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s, s = ' ' + s, dp[0][0][0] = fac[0] = 1;
	for(int i = 1, x; i <= n; i++)
		cin >> x, cnt[x]++, fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 0; i <= n; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = Sum(c[i - 1][j], c[i - 1][j - 1]);
	}
	for(int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];
	for(int i = 1; i <= n; i++) {
		int x = i & 1;
		if(s[i] == '0') {
			memset(dp[x], 0, sizeof(dp[x]));
			for(int j = 0; j < i; j++) {
				for(int k = 0; k <= i; k++) {
					int lim = min(i - k, cnt[j + 1] - cnt[j]);
					for(int p = 0; p <= lim; p++)
						dp[x][j + 1][k + p] = (dp[x][j + 1][k + p] + 1ll * dp[!x][j][k] * c[i - k][p] % mod * c[cnt[j + 1] - cnt[j]][p] % mod * fac[p]) % mod;
				}
				for(int k = 0; k <= min(cnt[j], i); k++) {
					int lim = min(i - 1 - k, cnt[j + 1] - cnt[j]);
					for(int p = 0; p <= lim; p++)
						dp[x][j + 1][k + p + 1] = (dp[x][j + 1][k + p + 1] + 1ll * dp[!x][j][k] * (cnt[j] - k) % mod * c[i - 1 - k][p] % mod * c[cnt[j + 1] - cnt[j]][p] % mod * fac[p]) % mod;
				}
			}
		}
		else {
			memcpy(dp[x], dp[!x], sizeof(dp[x]));
			for(int j = 0; j < i; j++)
				for(int k = 0; k <= min(i, cnt[j]); k++) {
					int lim = min(cnt[j + 1] - cnt[j], i - 1 - k);
					for(int p = 0; p <= lim; p++)
						dp[x][j + 1][k + p + 1] = (dp[x][j + 1][k + p + 1] + 1ll * dp[!x][j][k] * (cnt[j] - k) % mod * c[i - 1 - k][p] % mod * c[cnt[j + 1] - cnt[j]][p] % mod * fac[p]) % mod;
				}
		}
	}
	for(int i = 0; i <= n - m; i++)
		for(int j = 0; j <= n; j++)
			ans = (ans + 1ll * dp[n & 1][i][j] * c[cnt[n] - cnt[i]][n - j] % mod * fac[n - j]) % mod;
	cout << ans;
	return 0;
}