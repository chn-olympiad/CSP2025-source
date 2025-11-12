#include<bits/stdc++.h>
using namespace std;
long long dp[100010],a[100010],sum[100010];
long long n,k,lo,maxn;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			lo = sum[i] ^ sum[j - 1];
			if(lo == k)
			{
				dp[i] = max(dp[i],dp[j - 1] + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		maxn = max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
