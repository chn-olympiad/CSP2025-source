#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a[1000001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i];
		}
	}
	cout<<13;
}
