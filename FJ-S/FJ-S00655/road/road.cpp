#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],a[20],c[20][10010],maxn=0;
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
		cin>>a[i];
		maxn=max(maxn,a[i]);
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	cout<<maxn;
	return 0;
}
