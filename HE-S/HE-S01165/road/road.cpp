#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=1e4+10;
int n,m,k;
int c[15],a[15][N],u[M],v[M],w[M];
int f[N][N],ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		f[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int q=1;q<=k;q++)
	{
		for(int i=1;i<=m;i++)
		{
			/*f[u[i]][v[i]]*/ans+=min(f[u[i]][v[i]],c[q]+a[q][u[i]]+a[q][v[i]]);
		}
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

