#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#define intt long long
#define intu unsigned long long
#define dle double
#define dlel long double
using namespace std;
const int Imax=0x7fffffff;
const long long LLmax=0x7fffffffffffffff;
int qread()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9') res=res*10+ch-'0',ch=getchar();
	return res;
}
const int N=1e4+5;
const int X=1e3+5;
const int M=1e6+5;
int n,m,k;
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
int check(int x,int y){return find(x)==find(y);}
struct Graph{int u,v,w;}G[M];
int operator<(Graph a,Graph b){return a.w<b.w;}
int c[15],a[15][N];
int tot;
int dis[X][X];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(!k)
	{
		for(int i=1;i<=m;i++) scanf("%d%d%d",&G[i].u,&G[i].v,&G[i].w);
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(G+1,G+m+1);
		intt ans=0;
		for(int i=1;i<=m;i++)
		{
			if(check(G[i].u,G[i].v)) continue;
			ans+=G[i].w;
			merge(G[i].u,G[i].v);
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=2e9;
	for(int i=1;i<=m;i++)
	{
		G[i]=(Graph){qread(),qread(),qread()};
		dis[G[i].u][G[i].v]=dis[G[i].v][G[i].u]=min(dis[G[i].u][G[i].v],G[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			a[i][j]=qread();
			for(int k=1;k<j;k++) dis[j][k]=min(dis[j][k],a[i][j]+a[i][k]);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) G[++tot]=(Graph){i,j,dis[i][j]};
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(G+1,G+tot+1);
	intt ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(check(G[i].u,G[i].v)) continue;
		ans+=G[i].w;
		merge(G[i].u,G[i].v);
	}
	printf("%lld",ans);
	return 0;
}
