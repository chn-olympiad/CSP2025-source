#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5001],sum,maxn,cnt,ans,c[5001][5001];
void dfs(long long dep,long long maxn)
{
	if(dep>n)
	{
		if(cnt<3)return;
		if(sum>2*maxn)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	cnt++,sum+=a[dep];
	dfs(dep+1,max(maxn,a[dep]));
	cnt--,sum-=a[dep];
	dfs(dep+1,maxn);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	bool f=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f)
	{
		for(long long i=0;i<=n;i++)c[0][i]=1;
		for(long long i=1;i<=n;i++)
		{
			long long ddd=1;
			for(long long j=i;j<=n;j++)
			{
				if(i>j){c[i][j]=0;continue;}
				c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
			}
		}
		for(long long i=3;i<=n;i++)ans=(ans+c[i][n])%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
