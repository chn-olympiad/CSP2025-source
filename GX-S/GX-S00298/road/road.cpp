#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1e4+1;
struct wedge{
	long u,w;
	bool operator < (const wedge& a) const
	{
		return w > a.w;
	}
};
long edge[N][N],dge[N][11];
bool vis[N],edg[N][N];
int m,n,k,c[11];
priority_queue<wedge> p;
long long ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	
	for(int i=0,u,v,w;i<m;++i)
	{
		cin>>u>>v>>w;
		edge[u][v]=w;
		edge[v][u]=w;
		edg[u][v]=true;
		edg[v][u]=true;
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>dge[j][i];
		}
	}
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	for(int l=1;l<=k;++l)
	{if(edg[i][j])
		edge[i][j]=edge[j][i]=min(dge[i][l]+dge[j][l]+c[l],edge[i][j]);
		else edge[i][j]=edge[j][i]=dge[i][l]+dge[j][l]+c[l],edg[i][j]=edg[j][i]=true;
	}
	p.push({1,0});
	while(!p.empty())
	{
		auto dian=p.top();
		p.pop();
		if(vis[dian.u])
		continue;
		vis[dian.u]=true;
		ans+=dian.w;
		for(int i=1;i<=n;++i)
		if(!vis[i])
		p.push({i,edge[dian.u][i]});
	}
	cout<<ans<<endl;
	return 0;
}

