#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e4+5,M=1e6+5;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3f;
int n,m,k,fa[N+10],dep[N+10],sz[N+10],c[11],p[11],cnt;
LL ans;
struct ee
{
	int u,v,g;
	LL w;
	bool operator<(const ee xx)const{return w<xx.w;}
}e0[M],ed[M];
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
void mrg(int x,int y)
{
	x=fnd(x);
	y=fnd(y);
	if(dep[x]<dep[y])
	{
		fa[x]=y;
		sz[y]+=sz[x];
	}
	else if(dep[x]>dep[y])
	{
		fa[y]=x;
		sz[x]+=sz[y];
	}
	else
	{
		fa[x]=y;
		dep[y]++;
		sz[y]+=sz[x];
	}
}
void kruskal0()
{
	sort(e0+1,e0+m+1);
	cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int u=fnd(e0[i].u),v=fnd(e0[i].v);
		if(u!=v)
		{
			ed[++cnt]=e0[i];
			mrg(u,v);
		}
	}
}
LL kruskal()
{
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
		dep[i]=0;
	}
	for(int i=1;i<=n;i++)
		sz[i]=1;
	for(int i=n+1;i<=n+k;i++)
		sz[i]=0;
	LL res=0;
	for(int i=1;i<=cnt;i++)
		if(!ed[i].g||p[ed[i].g])
		{
			int u=fnd(ed[i].u),v=fnd(ed[i].v);
			if(u!=v)
			{
				res+=ed[i].w;
				mrg(u,v);
				if(sz[u]==n||sz[v]==n)
					return res;
			}
		}
	return res;
}
void dfs(int st,LL sm)
{
	if(st>k)
	{
		ans=min(ans,kruskal()+sm);
		return;
	}
	dfs(st+1,sm);
	p[st]=1;
	dfs(st+1,sm+c[st]);
	p[st]=0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e0[i].u>>e0[i].v>>e0[i].w;
	kruskal0();
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1,w;j<=n;j++)
		{
			cin>>w;
			ed[++cnt]={n+i,j,i,(LL)w};
		}
	}
	sort(ed+1,ed+cnt+1);
	ans=LINF;
	dfs(1,0);
	cout<<ans;
	return 0;
}
//meow!
