#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],sum[500005],ans,M,maxx[2000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	memset(maxx,-1,sizeof(maxx));
	maxx[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		dp[i] = max(M,maxx[sum[i]^k]+1);
		M = max(M,dp[i]);
		maxx[sum[i]] = max(maxx[sum[i]],dp[i]);
	}
	cout << dp[n];
	return 0;
}
