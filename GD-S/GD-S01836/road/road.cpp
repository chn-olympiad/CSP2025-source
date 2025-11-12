#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[15][10005];
struct edge{
	int u,v,w,bzz;
	edge(int _u=0,int _v=0,int _w=0,int _bzz=0){u=_u,v=_v,w=_w,bzz=_bzz;}
}g[2000005];
int bz[15];
bool cmp(edge a,edge b){return a.w<b.w;}
int fa[10005];
int bzz[2000005];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int now;
bool check(int nw)
{
	if(find(g[nw].u)==find(g[nw].v)) return 1;
	if(g[nw].bzz==0) return 0;
	if((now>>(g[nw].bzz-1))%2==1) return 0;
	else return 1;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i][0]);
		int mn=INT_MAX;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&c[i][j]);
			mn=min(mn,c[i][j]);
			if(c[i][j]==mn) bz[i]=j;
		}
		c[i][0]+=c[i][bz[i]];
		for(int j=1;j<=n;j++)
		{
			if(j==bz[i]) continue;
			g[++m]=edge(bz[i],j,c[i][j]);
			g[m].bzz=i;
		}
	}
	
	sort(g+1,g+1+m,cmp);
	long long anss=LLONG_MAX;
	int sx=(1<<k)-1;
	for(int i=0;i<=sx;i++)
	{
		bool s=0;
		long long ls1=0;
		for(int j=1;j<=k;j++)
		{
			if(c[j][0]==0&&((i>>(j-1))%2)!=1)
			{
				s=1;
				break;
			}
			if((i>>(j-1))%2==1) ls1+=c[j][0];
		}
		if(s==1) continue;
		for(int i=1;i<=n;i++) fa[i]=i;
		now=i;
		long long ans=0;
		int nw=1;
		for(int i=1;i<n;i++)
		{
			while(check(nw)&&nw<=m) nw++;
			if(nw>m) break;
			ans+=g[nw].w;
			fa[find(g[nw].u)]=find(g[nw].v);
			nw++;
		}
		if(nw<=m) anss=min(anss,ans+ls1);
	}

	printf("%lld",anss);
}
