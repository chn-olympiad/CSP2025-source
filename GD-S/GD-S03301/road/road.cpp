#include <iostream>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],w[m],c[k],a[k][n];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
}
