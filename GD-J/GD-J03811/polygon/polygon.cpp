#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int M = 1e6 + 10;
const long long mod = 998244353;
int n, a[N], sum[N];
long long ans = 0, dp[M], vis[M];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for(int i = n; i >= 1; --i) sum[i] = sum[i + 1] + a[i];
	dp[0] = 1ll;
	for(int i = n; i >= 1; --i)
	{
		for(int j = sum[i]; j >= a[i]; --j)
		{
			dp[j] += dp[j - a[i]];
			dp[j] %= mod;
		}
		if(n - i + 1 < 3) continue;
		for(int j = a[i] * 2 + 1; j <= sum[i]; ++j)
		{
			if(!vis[j]) ans += dp[j];
			else ans += (dp[j] - vis[j]);
			vis[j] = dp[j];
			ans %= mod;
		}
	}
	printf("%lld", ans % mod);
	return 0;
}
