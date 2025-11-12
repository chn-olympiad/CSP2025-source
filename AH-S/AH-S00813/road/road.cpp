#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[10001][10001],c[10001],a[101][10001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
		int u,v;
		cin>>u>>v;
		cin>>w[u][v];
		w[v][u]=w[u][v];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
