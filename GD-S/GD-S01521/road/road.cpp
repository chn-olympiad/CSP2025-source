#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
using ll=long long;
constexpr int N=1e4,K=10,M=1e6;
int n,m,k,cnt;
struct E
{
	int u,v,w;
}e[M+5],g[N+N*K+5],h[N+N*K+5];
int c[K+5];
int a[K+5][N+5];
int fa[N+K+5];
int getfa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=getfa(fa[x]);
}
ll ans=1e18;
void dfs(int x,int s,ll sm)
{
	if(x>k)
	{
		iota(fa+1,fa+1+n+k,1);
		fr(i,1,cnt) h[i]=g[i];
		sort(h+1,h+1+cnt,[](E A,E B){return A.w<B.w;});
		int num=0;
		fr(i,1,cnt)
		{
			int u=h[i].u;
			int v=h[i].v;
			int w=h[i].w;
			u=getfa(u),v=getfa(v);
			if(u!=v)
			{
				fa[u]=v;
				sm+=w;
				if(++num==n+s-1||sm>=ans) break;
			}
		}
		if(sm<ans) ans=sm;
		return;
	}
	dfs(x+1,s,sm);
	fr(i,1,n) if(a[x][i]<g[n-1].w) g[++cnt]={n+x,i,a[x][i]};
	dfs(x+1,s+1,sm+c[x]);
	fr(i,1,n) if(a[x][i]<g[n-1].w) --cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	fr(i,1,m)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	fr(i,1,k)
	{
		scanf("%d",&c[i]);
		fr(j,1,n) scanf("%d",&a[i][j]);
	}
	iota(fa+1,fa+1+n,1);
	sort(e+1,e+1+m,[](E x,E y){return x.w<y.w;});
	fr(i,1,m)
	{
		int u=e[i].u;
		int v=e[i].v;
		int w=e[i].w;
		u=getfa(u),v=getfa(v);
		if(u!=v)
		{
			fa[u]=v;
			g[++cnt]={u,v,w};
		}
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}