#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct edge
{
	int u,v,w;
}e[M*2];
int c[N],fa[N];
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cnt++;
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
		e[cnt+m+k*n]={e[cnt].v,e[cnt].u,e[cnt].w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cnt++;
			e[cnt].u=i+m,e[cnt].v=j;
			cin>>e[cnt].w;
			e[cnt+m+k*n]={e[cnt].v,e[cnt].u,e[cnt].w+c[i]};
		}
	}
	long long ans=0;
	sort(e+1,e+2*(m+k*n)+1,cmp);
	for(int i=1;i<=2*(m+k*n);i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v))
		{
			merge(u,v);
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}
