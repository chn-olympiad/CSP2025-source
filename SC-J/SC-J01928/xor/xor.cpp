#include <bits/stdc++.h>
using namespace std;
map<int,int> la;
int a[1000006],n,k;
int dp[1000006],sum[1000006];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(la[sum[i]^k]!=0)
		{
			dp[i]=max(dp[i],dp[la[sum[i]^k]]+1);
		}
		if(sum[i]==k)
		{
			dp[i]=max(dp[i],1);
		}
		la[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
} 