#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010][10010];
int u,v,w,b[20][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x7f7f7f7f,sizeof(a));
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w,a[v][u]=w;
	}
	for (int i=1;i<=n;i++)
		a[i][i]=0;
	for (int i=1;i<=k;i++)
	{
		cin>>b[i][0];
		for (int j=1;j<=n;j++)
			cin>>b[i][j];
	}
	for (int q=1;q<=k;q++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],b[k][i]+b[k][j]+b[k][0]);
	for (int q=1;q<=n;q++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	cout<<a[1][n];
	return 0;
}

