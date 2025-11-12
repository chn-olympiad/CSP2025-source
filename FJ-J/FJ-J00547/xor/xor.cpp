#include<bits/stdc++.h>
using namespace std;
int a,sum[500010],dp[500010];
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,maxa=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",&a);
		sum[i]=(sum[i-1]^a);
	}
	if(n<=1000)
	{
		int maxn=0;
		for(int i=n;i>=1;i--)
		{
			dp[i]=dp[i+1];
			for(int j=i;j<=n;j++)
			{
				if((sum[j]^sum[i-1])==k)
				{
					dp[i]=max(dp[j+1]+1,dp[i+1]);
					maxn=max(maxn,dp[i]);
					break;
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	int maxn=0;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		mp[sum[i]]=i+1;
		int x=(sum[i]^k);
		int y=mp[x];
		dp[i]=dp[i-1];
		if((sum[i]^sum[i-1])==k)
		{
			dp[i]++;
			y=0;
		}
		if(y&&i!=y-1)
		{
			dp[i]=max(dp[y-1]+1,dp[i]);
		}
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
