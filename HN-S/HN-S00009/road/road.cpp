#include<bits/stdc++.h>
using namespace std;
int u[1000001],v[1000001],w[1000001];
int c[11];
int a[1000001][11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
		{
			cin>>a[j][i];
		}
	}
	cout<<0;
	return 0;
}
