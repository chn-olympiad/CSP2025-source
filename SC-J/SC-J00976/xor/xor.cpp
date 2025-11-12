#include <bits/stdc++.h>
using namespace std;
int g[500005];
bool vis[500005];
int sum[500005];
int n,k_;
int dp[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k_;
	g[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> g[i];
		g[i] ^= g[i - 1];
	}
	int ans = 0;
	for(int i = n;i >= 1;i--)
	{
		for(int j = i + 1;j <= n;j++)
		{
			if((g[j] ^ g[i - 1]) == k_) dp[i] = max(dp[i],dp[j + 1] + 1);
		}
		if(g[i] == k_)
		{
			dp[i] = max(dp[i + 1] + 1,dp[i]);
		}
		dp[i] = max(dp[i],dp[i + 1]);
		ans = max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}