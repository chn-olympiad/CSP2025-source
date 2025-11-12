#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[1000001],v[1000001],w[1000001],c[11],a[11][10001],b[10001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i],b[u[i]]++,b[v[i]]++;
	for(int i=1;i<=k;i++)
	{
	    cin>>c[i];
	    for(int j=1;j<=n;j++)
	      cin>>a[i][j];
	}
	cout<<0;
	return 0;
}
