#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10,MAXM=11e6+10,MAXK=12;
int n,m,k;
struct node
{
	int u,v,w;
} edg[MAXM];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int a[MAXN];
int fa[MAXN];
int getfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].w);
	for(int i=1;i<=k;i++)
	{
		int c; scanf("%d",&c);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		for(int u=1;u<n;++u)
			for(int v=u+1;v<=n;++v)
			{
				++m;
				edg[m].u=u; edg[m].v=v;
				edg[m].w=a[u]+a[v];
			}
	}
	sort(edg+1,edg+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	for(int i=1;i<=m;++i)
		if(getfa(edg[i].u)!=getfa(edg[i].v))
		{
			ans+=edg[i].w;
			fa[fa[edg[i].u]]=fa[edg[i].v];
		}
	printf("%lld",ans);
	return 0;
}
