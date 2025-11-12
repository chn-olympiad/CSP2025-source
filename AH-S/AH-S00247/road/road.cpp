#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,cnt,fa[11100];
struct edge
{
	int u,v,w;
} e[1100010];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void add(int u,int v,int w)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	return x;
}
void Union(int x,int y)
{
	fa[x]=y;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			int v;
			cin>>v;
			add(n+i,j,c+v);
			add(j,n+i,c+v);
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)
		{
			Union(fx,fy);
			s+=e[i].w;
			cout<<s<<endl;
		}
	}
	cout<<s;
	return 0;
}
