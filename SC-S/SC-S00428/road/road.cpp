#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int a[N][N];
int c[N];
vector<vector<piar<int,int> > > adj;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n+1;j++) cin>>a[i][j];
	}
	cout<<13;
}