#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int MOD=998244353;
ll n,m,c[N],ans;
ll p[N];
bool vis[N];
char a[N];
bool check()
{
	ll peo=0,lea=0;
	for(int i=1;i<=n;i++)
	{
		if(lea>=c[p[i]]||a[i]=='0')
		{
			lea++;
			continue;
		}
		peo++;
		if(peo>=m) return true;
	}
	return false;
}
void dfs(ll level)
{
	if(level==n)
	{
		if(check())
		{
			ans=(ans+1)%MOD;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true) continue;
		p[level+1]=i;
		vis[i]=true;
		dfs(level+1);
		vis[i]=false;
		p[level+1]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",a+1);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='0')
		{
			flag=false;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	if(flag==true)
	{
		ans=1;
		for(ll i=2;i<=n;i++)
		{
			ans=(ans*i)%MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
