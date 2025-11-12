#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005, MOD = 998244353;
int n;
int a[N], dp[N][N], ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5000; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD;
		}
		dp[i][5001] = dp[i - 1][5001] % MOD;
		for (int j = 5001 - a[i]; j <= 5001; j++) dp[i][5001] = (dp[i][5001] + dp[i - 1][j]) % MOD;
	}
	for (int i = 3; i <= n; i++) {
		for (int j = a[i] + 1; j <= 5001; j++) ans = (ans + dp[i - 1][j]) % MOD;
	} cout << ans;
}
