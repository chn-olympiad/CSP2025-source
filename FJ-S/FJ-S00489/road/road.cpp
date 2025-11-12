#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int u,v,w;
}way[2000010];
int f[10010],c,b[10010];
long long int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	return f[x]=find(f[x]);
}
bool cmp(node a,node b)
{
	if(a.w==b.w)
	{
		if(a.u==b.u)
		{
			return a.v<b.v;
		}
		return a.u<b.u;
	}
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&way[i].u,&way[i].v,&way[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		int x=0;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&b[j]);
			if(b[j]==0)
			{
				x=j;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(x!=j)
			{
				way[++m].u=x;
				way[m].v=j;
				way[m].w=b[j];
			}
		}
	}
	sort(way+1,way+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(way[i].u),fy=find(way[i].v);
		if(fx!=fy)
		{
			f[fy]=fx;
			ans+=way[i].w;
		}
	}
	cout<<ans;
	return 0;
}
