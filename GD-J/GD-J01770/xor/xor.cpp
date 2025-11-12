#include<bits/stdc++.h>
using namespace std;

long long n,k,a[50001],s[50001],ans[10001][10001],dp[10001],f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i],s[i]=s[i-1]^a[i];
		if(a[i]!=1&&a[i]!=0)f=1;
	}
	if(!f)
	{
		if(k==1)
		{
			long long ans=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==1)ans++;
			}
			cout<<ans;
		}
		else if(k==0)
		{
			long long ans=0,cnt=0;
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==0)ans++,cnt=0;
				else cnt++;
				if(cnt==2)ans++,cnt=0; 
			}
			cout<<ans;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if((s[j]^s[i-1])==k)
			{
				ans[i][j]=1;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			dp[i]=max(dp[i],dp[i-1]);
			if(ans[i][j])dp[j]=max(dp[j],dp[i-1]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
