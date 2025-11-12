#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge
{
	int u,v,w;
}e[1100000];
int cnt;
int n,m,k;
int ans;
int fa[1100000];
int find(int x)
{
	if (x!=fa[x])
		return find(fa[x]);
	else
		return x;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e[++cnt]={u,v,w};
	}
	sort(e+1,e+cnt+1,cmp);
	int sum=0;
	for (int i=1;sum<n-1;i++)
	{
		int u=e[i].u,v=e[i].v;
		if (fa[u]!=fa[v])
		{
			fa[u]=find(fa[v]);
			sum++;
			ans+=e[i].w;
			//cout<<e[i].w<<' '<<i<<' ';
			//cout<<ans<<endl;
		}
	}
	printf("%lld",ans);
	return 0;
 } 
