#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10015][10015];
int w[10015][10015];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >>u>>v>>w;
		if(a[u][v]<=w)continue;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=n;i++)
	{
		a[i][i]=0;
		w[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
	}
	return 0;
}
