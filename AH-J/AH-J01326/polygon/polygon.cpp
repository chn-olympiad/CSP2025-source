#include <bits/stdc++.h>
using namespace std;

#define int long long
const int P = 998244353;
int n, m, ans;
int a[5005], dp[5005][5005];

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	m = a[n] + 1;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			if(j >= a[i]) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i]]) % P;
			else dp[i][j] = dp[i - 1][j];
		}
		dp[i][m] = dp[i - 1][m];
		for(int j = m - a[i]; j <= m; j++)
			(dp[i][m] += dp[i - 1][j]) %= P;
	}
	for(int i = 3; i <= n; i++)
		for(int j = a[i] + 1; j <= m; j++)
			(ans += dp[i - 1][j]) %= P;
	cout << ans << endl;
	return 0;
}
