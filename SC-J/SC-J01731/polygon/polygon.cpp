#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010, M = 1e4 + 10;
const int mod = 998244353;
int a[N]/*, dp[N][M]*/, sum[M];
int dp[M];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dp/*[0]*/[0] = 1, sum[0] = 1;
	int ans = 0;
	// 1, 2, 3, 4, 5
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < M; j++) {
			int x = max(0LL, j - a[i]);
//			for (int k = 0; k < i; k++) dp[i][j] += dp[k][x];
			dp/*[i]*/[j] = sum[x];
		}
		for (int j = 0; j < M; j++) {
			(sum[j] += dp/*[i]*/[j]) %= mod;
		}
		// sum > 2 * a[i]
		(ans += dp/*[i]*/[2 * a[i] + 1]) %= mod;
	}
	cout << ans << "\n";
	return 0;
}