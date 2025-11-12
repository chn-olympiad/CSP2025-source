#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n;
map<string,bool>have;
long long ans=0;
long long a[6000];
long long b[6000];
long long vis[6000];
long long dp[5001][5001];
void dfs(int k,long long maxn,long long sum)
{
	
	if(k>=3&&sum>(2*maxn)&&k<=n)
	{
		string s="";
		for(int i=1;i<=n;i++)
		{
			char q;
			if(vis[i]!=0)
			{
				q='0'+a[i];
				s+=q;
			}
		}
		if(have[s]!=1)
		{
			ans=(ans%mod+1%mod)%mod;
			have[s]=1;
		}
	}
	if(k>n)return;
	if(sum<=(2*maxn)&&k>=3)return;
	int l=maxn;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]!=0)continue;
		if(maxn<=a[i])maxn=a[i];
		sum+=a[i];
		vis[i]=1;
		dfs(k+1,maxn,sum);
		vis[i]=0;
		sum-=a[i];
		maxn=l;
	}
}
long long maxq=-1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxq=max(maxq,a[i]);
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		long long sum=0,maxn=-1;
		for(int i=1;i<=n;i++)
		{
			max(maxn,a[i]);
			sum+=a[i];
		}
		if(2*maxn>=sum)
		{
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(n>3)
	{
		if(maxq==1)
		{
			cout<<1;
			dp[0][1]=dp[1][1]=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i==j)dp[i][j]=1;
					if(i>=j)continue;
					dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j-1]%mod)%mod;
					if(j==n)ans=(ans%mod+dp[i][n]%mod)%mod;
				}
			}
			cout<<ans;
			return 0;
		}
		dfs(0,0,0);
	}
	cout<<(ans+1)%mod;
	return 0;
}


