#include<bits/stdc++.h>
using namespace std;

int n,m,k,tot,ans;
int hd[2000010],fa[2000010],c[200010],a[10][20010];
vector<pair<int,pair<int,int> > > ve;
struct edge{int v,w,nxt;}eg[2000010];
int fid(int k)
{
	if(k==fa[k])
		return k;
	return fa[k]=fid(fa[k]);
}
void add(int u,int v,int w)
{
	eg[++tot].v=v;
	eg[tot].w=w;
	eg[tot].nxt=hd[u];
	hd[u]=tot;
}
priority_queue<pair<int,pair<int,int> > > pq;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=k+n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
//		add(u,v,w);
//		add(v,u,w);
		pq.push({-w,{u,v}});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			pq.push({-a[i][j],{i,j}});
		}
	}
	while(!pq.empty())
	{
		auto awa=pq.top();
		pq.pop();
		int w=-awa.first,u=awa.second.first,v=awa.second.second;
		int fu=fid(fa[u]);
		int fv=fid(fa[v]);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ve.push_back({w,{u,v}});
			ans+=w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}