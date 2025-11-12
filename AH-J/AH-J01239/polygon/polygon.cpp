#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,maxn,a[10000],f[501][50001],g[501][50001],mod=998244353;
long long quickpow(long long x,long long y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x;
	long long tmp=quickpow(x,y/2);
	if(y%2==0)
		return tmp*tmp%mod;
	return tmp*tmp%mod*x%mod;
}
void dfs(int u,int cnt,long long maxn,long long sum)
{
	if(u==n+1)
	{
		if(cnt>=3&&sum>maxn*2)
		{
			//~ cerr<<'#'<<cnt<<' '<<maxn<<' '<<sum<<'\n';
			ans++;
		}
		return;
	}
	dfs(u+1,cnt+1,max(maxn,a[u]),sum+a[u]);
	dfs(u+1,cnt,maxn,sum);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n<=20)
	{
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	if(maxn==1)
	{
		long long sum=2;
		for(int i=3;i<=n;i++)
		{
			sum=sum*i%mod;
			long long tmp=n;
			for(long long j=n-1;j>=n-i+1;j--)
				tmp=tmp*j%mod;
			tmp=tmp*quickpow(sum,mod-2)%mod;
			ans+=tmp;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	//~ sort(a+1,a+n+1,less<long long>());
	//~ f[0][0]=1;
	//~ g[0][0]=1;
	//~ for(int i=1;i<=n;i++)
	//~ {
		//~ for(int j=0;j<=50000;j++)
		//~ {
			//~ g[i][j]=f[i-1][j]+g[i-1][j];
			//~ g[i][j]%=mod;
			//~ f[i][j]=f[i-1][j-a[i]]+g[i-1][j-a[i]];
			//~ f[i][j]%+mod;
		//~ }
	//~ }
	return 0;
}//sro %%% lzn AK CSP-J %%% orz
