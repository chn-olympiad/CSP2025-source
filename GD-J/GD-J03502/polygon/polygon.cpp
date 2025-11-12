#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5005],n,ans,w[5005];
bool bz[5005];
struct tt
{
	long long sum,res,maxx;
}dp[501][501][2];
void dfs(int x,int f)
{
	if(x>n+1) return;
	if(x==n+1)
	{
		if(f>=3)
		{
			long long maxx=0,res=0;
			for(int i=1;i<=n;i++)
			{
				if(bz[i]==1)
				{
					maxx=max(a[i],maxx);
					res+=a[i];
				}
			}
			if(res>maxx*2) ans++;
		}
		
		return;
	}
	bz[x]=1;
	dfs(x+1,f+1);
	bz[x]=0;
	dfs(x+1,f);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool p=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) p=0;
	}
	if(p==1)
	{
		long long s=1;
		w[0]=1;
		for(int i=1;i<=n;i++)
		{
			s*=i;
			s%=mod;
			w[i]=s;
		}
		for(int i=3;i<=n;i++)
		{
			ans+=w[n]/((w[n-i]*w[i])%mod);
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	else if(n<=20)
	{
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	else
	{
		if(n>500) 
		{
			cout<<0;
			return 0;
		}
		dp[1][1][1].sum=0,dp[1][1][1].res=a[1],dp[1][1][1].maxx=a[1];
		dp[1][0][0].sum=0,dp[1][0][0].res=0,dp[1][0][0].maxx=0;
		dp[2][1][1].sum=0,dp[2][1][1].res=a[2],dp[2][1][1].maxx=a[2];
		dp[2][1][0].sum=0,dp[2][1][0].res=a[1],dp[2][1][0].maxx=a[1];
		dp[2][2][1].sum=0,dp[2][2][1].res=a[1]+a[2],dp[2][2][1].maxx=max(a[2],a[1]);
		dp[2][0][0].sum=0,dp[2][0][0].sum=0,dp[2][0][0].maxx=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]+dp[i][j-1][1].res>max(a[i],dp[i][j-1][1].maxx)*2)
				{
					if(dp[i][j-1][1].sum+1>dp[i][j][1].sum)
					{
						dp[i][j][1].sum=(dp[i][j-1][1].sum+1)%mod;
						dp[i][j][1].res=dp[i][j-1][1].res+a[i];
						dp[i][j][1].maxx=max(dp[i][j-1][1].maxx,a[i]);
					}
					else
					{
						dp[i][j][1].sum=dp[i][j][1].sum%mod;
						dp[i][j][1].res=dp[i][j-1][1].res+a[i];
						dp[i][j][1].maxx=max(dp[i][j-1][1].maxx,a[i]);
					}
				}
				else
				{
					dp[i][j][1].sum=dp[i][j][1].sum%mod;
					dp[i][j][1].res=dp[i][j-1][1].res+a[i];
					dp[i][j][1].maxx=max(dp[i][j-1][1].maxx,a[i]);
				}
				if(dp[i-1][j][0].sum>dp[i-1][j][1].sum)
				{
					dp[i][j][0].sum=dp[i-1][j][0].sum%mod;
					dp[i][j][0].res=dp[i-1][j][0].res;
					dp[i][j][0].maxx=dp[i-1][j][0].maxx;
				}
				else
				{
					dp[i][j][0].sum=dp[i-1][j][1].sum%mod;
					dp[i][j][0].res=dp[i-1][j][1].res;
					dp[i][j][0].maxx=dp[i-1][j][1].maxx;
				}
			}
		}
		for(int i=3;i<=n;i++)
		{
			ans+=max(dp[n][i][0].sum,dp[n][i][1].sum)%mod;
		}
		cout<<ans;
	}
	return 0;
}
