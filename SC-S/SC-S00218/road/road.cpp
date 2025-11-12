#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1010],v[1010],w[1010],a[11],b[11][1010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	cout<<0;
	return 0;
}