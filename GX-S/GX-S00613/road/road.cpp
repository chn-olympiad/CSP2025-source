#include<bits/stdc++.h>
using namespace std;
struct edg
{
	int v,w;
};
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<edg>> g(n+1);
	vector<vector<int>> v(k,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<k;i++)
		for(auto& j:v[i])
			cin>>j;
}
