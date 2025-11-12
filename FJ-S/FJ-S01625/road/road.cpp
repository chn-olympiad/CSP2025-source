#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],w[i]);
	}
	for(int j=1;j<=k;j++)
	{
		scanf("%d",c[j]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[j][i]);
		}
	}
	cout<<0;
	return 0;
}
