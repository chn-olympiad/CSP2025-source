#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll p=998244353;
ll n,m,f[19],sum,ans,c[20],res,b[20];
bool v[20];char s[20];
void init()
{
	f[0]=1;f[1]=1;
	for(ll i=2;i<=18;i++)f[i]=f[i-1]*i;
	return;
}
void dfs(ll w)
{
	if(sum==m)
	{
		ans=(ans+f[n-w+1])%p;
		return;
	}
	if(w==n+1)return;
	bool pd=0;
	for(ll i=1;i<=n;i++)if(v[i]==0)pd=1;
	if(pd==0)return;
	if(s[w]=='1')
	{
		for(ll i=1;i<=n;i++)if(v[i]==0)
		{
			sum++;v[i]=1;
			dfs(w+1);
			sum--;v[i]=0;
		}
	}
	else
	{
		int l=0;
		for(ll i=1;i<=n;i++)if(v[i]==0)
		{
			c[i]--;b[++l]=i;
			if(c[i]==0)v[i]=1;
		}
		for(ll i=1;i<=l;i++)if(v[b[i]]!=0)
		{
			v[b[i]]=1;
			dfs(w+1);
			v[b[i]]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();memset(v,0,sizeof v);
	memset(b,0,sizeof b);
	ans=0;sum=0;
	scanf("%lld%lld%s",&n,&m,s+1);
	for(ll i=1;i<=n;i++)scanf("%lld",&c[i]);
	dfs(1);printf("%lld\n",ans);
	return 0;
}
