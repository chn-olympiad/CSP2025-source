#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int NR=1e4+105;
const int MR=1e6+105;
struct Edge
{
	int u,v,w;
	bool operator <(const Edge &b)const
	{
		return w<b.w;
	}
}g[MR],e[MR];
int fa[NR];
int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int c[15],a[15][NR];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,K;scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
	sort(g+1,g+m+1);
	int num=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int fx=getfa(g[i].u),fy=getfa(g[i].v);
		if(fx==fy) continue;
		g[++num]=g[i];
		fa[fx]=fy;
		//printf("%d %d %d\n",g[i].u,g[i].v,g[i].w);
	}
	for(int i=0;i<K;++i)
	{
		scanf("%d",c+i);
		for(int j=1;j<=n;++j) scanf("%d",a[i]+j);
	}
	LL ans=9e18;
	int ct=0;
	for(int i=0;i<K;++i)
	{
		for(int j=1;j<=n;++j) e[++ct]=(Edge){n+i+1,j,a[i][j]};
	}
	for(int j=1;j<n;++j) e[++ct]=g[j];
	sort(e+1,e+ct+1);
	for(int s=0;s<(1<<K);++s)
	{
		LL sum=0;
		for(int i=0;i<K;++i) if(s>>i&1)
		{
			sum+=c[i];
		}
		for(int i=1;i<=n+K;++i) fa[i]=i;
		for(int i=1;i<=ct;++i)
		{
			if(e[i].u<=n||(s>>(e[i].u-n-1)&1));
			else continue;
			int fx=getfa(e[i].u),fy=getfa(e[i].v);
			if(fx==fy) continue;
			//if(s==1) printf("%d %d\n",e[i].u,e[i].v);
			fa[fx]=fy;
			sum+=e[i].w;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}