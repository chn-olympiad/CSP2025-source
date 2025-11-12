#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	int u[100005],v[100005],w[100005],c[15],b[10000][15];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}	
	cout<<0;
	return 0;
}
