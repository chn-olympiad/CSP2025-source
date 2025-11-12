//GZ-S00215 贵阳市第一中学  李啸峰 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct Edge{
	int u,v,w,ne;
}e[N];
int n,m,k,fa[N],Ans,tot,head[N];
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void add(int u,int v,int w)
{
	++tot;
	e[tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	e[tot].ne=head[u];
	head[u]=tot;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
void kruscal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	stable_sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i+=2)
	{
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)
			continue;
		Ans+=e[i].w;
		fa[v]=fa[u];
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}	
	kruscal();
	cout<<Ans<<endl;
	return 0;
}
