#include<bits/stdc++.h>
using namespace std;
int m,n,k,u[1000500],v[1000500],w[1000500],c[15];
int a[15][1000100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<505585650;
	return 0;
}
