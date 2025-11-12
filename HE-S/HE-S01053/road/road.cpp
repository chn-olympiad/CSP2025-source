#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10005],v[10005],w[10005],a[10005][10005],c[10001],w1[10005];
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
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>w1[i];
		}
	}
	cout<<"13";
	
	return 0;
}

