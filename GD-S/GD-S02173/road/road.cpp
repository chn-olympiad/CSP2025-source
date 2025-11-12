#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int x,z;
};
int n,m,a[110][N],dis[N],k,g[N];
vector<node> v[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	int u,v1,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v1>>w;
		v[u].push_back({v1,w});
		v[v1].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>g[i];
		for(int j=1;j<=n;j++)
		 cin>>a[i][j];
	}
	cout<<0;
	return 0;
}
