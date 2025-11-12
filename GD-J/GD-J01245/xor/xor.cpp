#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],p[N],cnt,dp[N],la[N],op=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]>1)op=0;
	}
	if(op)
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1,num=0;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
					ans+=num/2;
					num=0;
				}
				else num++;
			}
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			dp[i]=max(dp[i],dp[j]);
		}
		if(a[i]==k)
		{
			dp[i]++;
			la[i]=1;
//			cout<<dp[i]<<" ";
			continue;
		}
		for(int j=1;j<i;j++)
		{
			if((sum[i]^sum[j-1])==k)
			{
				if(!la[j])
				{
					if(dp[j]+1>dp[i])
					{
						la[i]=1;
						dp[i]=dp[j]+1;
					}
				}
			}
		}
//		cout<<dp[i]<<" ";
	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<la[i]<<" ";
	cout<<dp[n];
	return 0;
}
