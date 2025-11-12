#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100100][100100],c[100100];
int main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[m+i][j]; 
		} 
	}
	
	return 0;
}
