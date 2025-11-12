#include <bits/stdc++.h>
using namespace std;
int n,m,k,num;
int u[10000005],v[10000005],w[10000005],c[10000005],a[10005][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		num+=w[i];
	}
	cout<<num;
	return 0;
}
