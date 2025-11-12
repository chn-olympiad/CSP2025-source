# include<bits/stdc++.h>
# define N 5005
using namespace std;
const int Mod = 998244353;
int n, maxn, ans, a[N], dp[N][N << 1];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0) -> ios :: sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1), maxn ++;
	maxn += 2025;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= maxn; j ++)
			dp[i][j] = dp[i - 1][j];
		for(int j = 0; j <= maxn; j ++)
			dp[i][min(maxn, a[i] + j)] = (dp[i][min(maxn, a[i] + j)] + dp[i - 1][j]) % Mod;
		for(int j = a[i] + 1; j <= maxn; j ++)
			ans = (ans + dp[i - 1][j]) % Mod;
	}
	cout << ans << "\n";
	return 0;
}