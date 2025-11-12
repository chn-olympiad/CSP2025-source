#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=2e6+17;
ll n,m,k,f[maxn],ans=1e16+7;
bool vis[maxn];
ll head[maxn],nxt[maxn],to[maxn],val[maxn],cnt;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	 } 
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
 } 
void write(ll x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	x<10?putchar(x|48):(write(x/10),putchar(x%10|48));
}
void add(ll u,ll v,ll w)
{
	cnt++;
	nxt[cnt]=head[u];
	to[cnt]=v;
	val[cnt]=w;
	head[u]=cnt; 
}
void dfs(ll u,ll sum)
{
	bool fl=0;
	for(ll i=1;i<=n;i++)if(!vis[i])fl=1;
	if(fl==0)
	{
		ans=min(ans,sum);
		return;
	}
	ll v;
	for(ll i=head[u];i;i=nxt[i])
	{
		v=to[i];
		if(vis[v])continue;
		vis[v]=1;
		dfs(v,sum+val[i]);
		vis[v]=0;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll u,v,w,x,a,b,h;
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<=m;i++)
	{
		u=read();
		v=read();
		w=read();
		add(u,v,w);
		add(v,u,w);
	}
	for(ll i=1;i<=k;i++)
	{
		h=read();
		for(ll j=1;j<=n;j++)
		{
			x=read();
			add(i+n,j,h+x);
			add(j,i+n,h+x);
		}
	}
	vis[1]=1;
	dfs(1,0);
	write(ans);
	putchar('\n');
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/