#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u,v,w,f[1005][1005],c[1005],a[1005][1005],d[1005],vis[1005],inf=0x3f3f3f3f,ma;
struct node
{
	int v,w;
};
vector<node> e[1005];
void dij(int u)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(d,inf,sizeof d);
	memset(vis,0,sizeof vis);
	d[u]=0;
	q.push({0,u});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].v,w=e[u][i].w;
			if(d[u]>d[v]+w)
			{
				d[u]=d[v]+w;
				q.push({d[v],v});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			f[i][j]=inf;
			if(i==j)  f[i][j]=0ll;
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
		f[u][v]=min(f[u][v],w);
		f[v][u]=min(f[v][u],w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		for(int j=1;j<=n;j++)
		{
			for(int g=1;g<=n;g++)
			{
				f[j][g]=min(f[j][g],c[i]+a[i][j]+a[i][g]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dij(i);
		for(int j=1;j<=n;j++)  f[i][j]=min(f[i][j],d[j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ma=max(ma,f[i][j]);
		}
	}
	cout<<ma; 
	return 0;
} 
