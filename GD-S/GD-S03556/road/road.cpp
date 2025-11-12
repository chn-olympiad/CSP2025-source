#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=1e18;
bool SpecialA=true;
int c[15],a[15][10015],dis[10015];
bool vis[10015],put[15];
struct edge{
	int v,w;
};
vector<edge> to[10015];
int Prim()
{
	int res=0,realN=n;
	
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));dis[1]=0;
	
	for(int i=1;i<=k;i++)
		if(put[i])
		{
			realN++;res+=c[i];
			for(int j=1;j<=n;j++)
			{
				to[realN].push_back({j,a[i][j]});
				to[j].push_back({realN,a[i][j]});
			}
		}
	for(int t=1;t<=realN;t++)
	{
		int u,last=1e18;
		for(int i=1;i<=realN;i++)
		{
			if(!vis[i]&&dis[i]<last)
				last=dis[i],u=i;
		}
		vis[u]=true;
		res+=last;
		for(edge e:to[u])
		{
			int v=e.v;
			dis[v]=min(dis[v],e.w);
		}
	}
	for(int i=k;i>=1;i--)
		if(put[i])
		{
			to[realN].clear();
			for(int j=1;j<=n;j++)
			{
				to[j].erase(to[j].end()-1);
			}
			realN--;
		}//DEL
	return res;
}
void dfs(int p)
{
	if(p==k+1)
	{
		ans=min(ans,Prim());
		return;
	}
	put[p]=true;dfs(p+1);
	put[p]=false;dfs(p+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		edge put;int u;
		scanf("%lld%lld%lld",&u,&put.v,&put.w);
		to[u].push_back(put);
		to[put.v].push_back({u,put.w});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		SpecialA=SpecialA and c[i]==0;
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	if(SpecialA)
	{
		for(int i=1;i<=k;i++)put[i]=true;
		cout<<Prim();
	}
	else
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
