#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5; 
vector<pair<int,int>>g[N];
int c[50];
bool vis[N];
bool vis2[N];
long long dfs(int u,int fa)
{
	long long sum=0;
	for(pair<int,int> v:g[u])
	{
		if(v.first==fa)continue;
		if(!vis[v.first])
		{
			vis[v.first]=1;
			sum+=dfs(v.first,u)+v.second;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	long long ans=1e18;
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		ans=min(ans,dfs(i,0));
		memset(vis,0,sizeof vis);
		vis[i]=0;
	}
	int u=n;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=u;j++)
		{
			int w;
			cin>>w;
			g[++n].push_back({j,w});
			g[j].push_back({n,w});
		}
	}
	for(int j=1;j<=(1<<k)-1;j++) 
	{
		int sum1=0;
		for(int i=0;i<k;i++)
		{
			if((1<<i)&j)
			{
				vis2[n+i+1]=1;
				sum1+=c[i+1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int i=0;i<k;i++)
			{
				vis[n+i+1]=vis2[n+i+1];
			}
			if(vis[i])
			vis[i]=1;
			ans=min(ans,dfs(i,0)+sum1);
			memset(vis,0,sizeof vis);
		}
		memset(vis2,0,sizeof vis2);
	}
	
	cout<<ans;
	return 0;
} 
