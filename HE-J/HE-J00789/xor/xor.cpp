#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500010];
long long sum[500010],fin[500010],dp[500010];
bool pd;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) pd=1;
	}
	if(!pd)
	{
		if(k!=0&&k!=1)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k) ans++;
			else if(k==0&&a[i]==a[i-1]&&a[i]==1)
			{
				ans++;
				a[i]=0;
			}
		}
		cout<<ans;
		return 0;
	}
	sum[1]=a[1];
	if(a[1]==k) fin[1]=1;
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
		if(sum[i]==k&&!fin[1])
		{
			fin[1]=i;
		}
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			long long x=sum[j]^sum[i-1];
			if(x==k)
			{
				if(fin[i]==0) fin[i]=j;
				else fin[i]=min(fin[i],j);
//				cout<<i<<" "<<j<<"\n";
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(fin[i]) dp[fin[i]]=1;
		else continue;
		for(int j=1;j<=n;j++)
		{
			if(fin[j]<i)
			{
				dp[fin[i]]=max(dp[fin[i]],dp[fin[j]]+1);
			}
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/
