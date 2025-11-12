#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	ll n,m,k;
	cin>>n>>m>>k;
	ll u[100010],v[100010],w[1000010];
	ll c[100010],a[100010];
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
	}
	cout<<n+m+k+v[k];
	return 0;
}

