#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000;
int n,m,k,minn=1e9+1,vis,cost[N+100];
struct tt
{
	int x,val;
};
vector<tt>a[N+100];
bool bz[N+100];
void dfs(int x,int fa,int ans,int vis)
{
	bz[x]=1;
	if(vis==n)
	{
		
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<a[x].size();i++)
	{
		int u=a[x][i].x;
		int val=a[x][i].val;
		if(u==fa||bz[u]==1) continue;
		if(u<=n) dfs(u,x,ans+val,vis+1);
		else dfs(u,x,ans+val+cost[u],vis);
		bz[u]=0;
	}
 } 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		cin>>w;
		cost[n+i]=w;
		for(int j=1;j<=n;j++)
		{
			int z;
			cin>>z;
			a[n+i].push_back({j,z});
			a[j].push_back({n+i,z});
		}
	}
	dfs(1,0,0,1);
	cout<<minn;
	return 0;
}
