#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5100;
const int Mod = 998244353;
int n;
int a[N];
int ans;
void dfs(int tot, int sum, int m, bool p)
{
	if (sum > a[tot] * 2 && m >= 3 && p) ans++;
	if (tot == n)
	{
		return;
	}
	dfs(tot + 1, sum + a[tot + 1], m + 1, true);
	dfs(tot + 1, sum, m, false);
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort (a + 1, a + 1 + n);
	dfs(0, 0, 0, 0);
	printf("%lld", ans % Mod);
	return 0;
//	for (int i = 1; i <= n; i++)
//	{
//		b[i] = a[i];
//		b[i] += b[i - 1];
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		for (int j = 3; j <= i; j++)
//		{
//			dp[i][j] = dp[i - 1][j];
//			for (int k = 1; k <= i - j + 1; k++)//取连续的木棍 
//			{
//				if (b[k + j - 1] - b[k - 1] > a[i] * 2)
//				{
//					dp[i][j] += i - (k + j - 1) + 1;
//				}
//			}
//			val = a[i];
//			m = i;
//			p = j;
//			dp[i][j] += dfs(0, 0, 0, 0, 0);//取不连续的木棍
//			dp[i][j] %= Mod;
////			cout << i << " " << j << " " << dp[i][j] << endl;
//		}
//	}
//	for (int i = 3; i <= n; i++)
//	{
//		ans += dp[n][i];
//		ans %= Mod;
////		cout << i << " " << dp[n][i] << endl;
//	}
}
/*
dp[i][j] = 前i个木棍拼成j边形的方案数
dp[i][j] = dp[i - 1][j] + 
*/
