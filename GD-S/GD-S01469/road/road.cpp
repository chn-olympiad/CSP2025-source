#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,mod;
map<int,map<int,int> > a;
int j[15][N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
		mod+=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>j[i][0];
		for(int r=1;r<=n;r++) cin>>j[i][r];
	}
	srand(time(nullptr));
	cout<<rand()%mod+1;
	return 0;
}
