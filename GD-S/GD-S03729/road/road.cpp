#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int to,w;
};
vector<vector<road>> lst;
vector<int> c;
vector<vector<int>> a;
vector<bool> vis;
int dfs(int x)
{
	vis[x]=true;
	int ans=0;
	for(auto i:lst[x])
	{
		if(vis[i.to]) continue;
		ans+=dfs(i.to)+i.w;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	lst.resize(n+1);
	c.resize(n+1);
	vis.resize(n+1);
	a.assign(k+1,vector<int>(n+1));
	int u,v,w;
	for(int i=0;i<n;i++)
	{
		cin>>u>>v>>w;
		lst[u].push_back({v,w});
		lst[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<dfs(1);
	return 0;
}
