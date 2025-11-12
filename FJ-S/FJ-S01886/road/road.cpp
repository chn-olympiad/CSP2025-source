#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,fa[11000005],sum,cnt,a[11000005],v[11000005],b[1005][1005];
struct node
{
	int u,v,w;
} e[11000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(b,0x3f3f,sizeof(b));
	cin >>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		b[u][v]=min(b[u][v],w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&v[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if (i==k) continue;
				b[j][k]=min(b[j][k],a[j]+a[k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[++sum].u=i;
			e[sum].v=j;
			e[sum].w=b[i][j];
		}
	}
	sort(e+1,e+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		int u=e[i].u,v=e[i].v;
		int fu=find(u);
		int fv=find(v);
		if (fu!=fv)
		{
			fa[fu]=fv;
			ans+=e[i].w;
			cnt++;
			if (cnt==n-1) break;
		}
	}
	cout <<ans;
	return 0;
}

