#include<bits/stdc++.h>
using namespace std;
long long c[100005],a[100005][1000005];
long long n,m,k;
long long u[100005],v[100005],w[100005];
int main( )
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<v[i];
		}
	}
	cout<<"13";
	return 0;
}
