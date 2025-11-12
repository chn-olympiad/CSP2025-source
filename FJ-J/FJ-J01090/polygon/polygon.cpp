#include <bits/stdc++.h>
using namespace std;

int n, a[5005]; long long ans, sum[5005], dp[5005][30005];
const int MOD = 998244353;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i];
		sum[i] = (sum[i - 1] + a[i]) % MOD;
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i ++) dp[i][a[i]] = 1; 

	for (int i = 1; i <= n; i ++) 
		for (int j = 0; j < i; j ++)
			for (int k = a[i]; k <= sum[i]; k ++)
				dp[i][k] = (dp[i][k] + dp[j][k - a[i]]) % MOD; 
				
	for (int i = 1; i <= n; i ++)
		for (int j = 2 * a[i] + 1; j <= sum[i]; j ++)
			ans = (ans + dp[i][j]) % MOD;
	cout << ans << endl;
	return 0;
}
// dp[i][j]表示以第i根为结尾，长度之和为j的方案数之和 
