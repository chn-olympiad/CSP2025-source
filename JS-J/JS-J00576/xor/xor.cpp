#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, x[500005], sum[500005], dp[500005];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf ("%lld%lld" , &n , &k);
	for (int i = 1; i <= n; i++)
	{
	   scanf ("%lld", &x[i]);
	   sum[i] = sum[i - 1] ^ x[i];
	}
	for (int i = 1; i <= n + 1; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);
		for (int j = i; j <= n; j++)
			if ((sum[j] ^ sum[i - 1]) == k)
				dp[j + 1] = max(dp[j + 1], dp[i] + 1);
	}
	cout << dp[n + 1];
	return 0;
}
