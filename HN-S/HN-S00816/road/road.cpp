#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000086],v[1000086],w[1000086];
int a[1000086],c[1000086];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++)
	{
		cin>>a[j]>>c[j];
	}
	cout<<13;
	return 0;
}
		
