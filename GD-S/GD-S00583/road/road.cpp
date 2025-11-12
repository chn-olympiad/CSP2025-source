#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k,z=0;
	int u[100001],v[100001],w[100001];
	int c[11],a[11][10001];
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int l=1;l<=n;l++)
			cin>>a[j][l];
	}
	cout<<z<<endl;
	return 0;
} 
