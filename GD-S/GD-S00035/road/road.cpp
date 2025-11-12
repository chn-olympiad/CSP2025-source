#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+5,M=5e6+5;
int n,m,k,cnt;
LL ans;
struct edge { int u,v,w; } e[M];
int fa[N],num[N],a[15][N];
map<pair<int,int>,int> mp;
int Find(int x) { return (x==fa[x] ? x : fa[x]=Find(fa[x])); }
void Kruskal()
{
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+cnt,[](edge a,edge b) { return a.w<b.w; });
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int rx=Find(u),ry=Find(v);
		if(rx==ry) continue;
		ans+=w;
		fa[rx]=ry; 
	}
}
int main()
{
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			mp[make_pair(j,i)]=-1;
	for(int i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		mp[make_pair(e[i].u,e[i].v)]=e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&num[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			for(int p=1;p<j;p++)
			{
				pair<int,int> pr=make_pair(p,j);
				if(mp[pr]==0) mp[pr]=a[i][p]+a[i][j];
				else mp[pr]=min(mp[pr],a[i][p]+a[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(mp[make_pair(j,i)]!=-1)
				e[++cnt]={j,i,mp[make_pair(j,i)]};
	Kruskal(); 
	printf("%lld",ans);

	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
*/
