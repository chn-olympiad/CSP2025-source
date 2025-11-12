#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>e[100005];
int a[15][10005],b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		for(int j=1;j<=k;j++)
			e[u+(j-1)*(n+1)].push_back({u+(j-1)*(n+1),w}),e[v+(j-1)*(n+1)].push_back({v+(j-1)*(n+1),w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			e[j+(i-1)*(n+1)].push_back({(k+1)*i,a[i][j]});
			e[(k+1)*i].push_back({j+(i-1)*(n+1),a[i][j]});
			e[j+i*(n+1)].push_back({(k+1)*i,a[i][j]});
			e[(k+1)*i].push_back({j+i*(n+1),a[i][j]});
		}
	}
	return 0;
}
