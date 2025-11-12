#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;
map<int,map<int,int>>b;
int c[11],a[11][N];
long long z;
int n,m,k,u,v,w,i,j;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		b[u][v]=w;
		b[v][u]=w;
		z+=w;
	}
	for(i=1;i<=k;++i)
	{
		cin>>c[i];
		for(j=1;j<=n;++j)cin>>a[i][j];
	}
	cout<<z;
	return 0;
}
