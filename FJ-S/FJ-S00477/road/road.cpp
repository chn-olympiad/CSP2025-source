#include <bits/stdc++.h>
using namespace std;
int v[1000010],u[1000010],w[1000010],c[10010],a[10010];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
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
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int minv=2e9,minx=2e9,minc=2e9;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		minv=min(minv,w[i]);
		ans+=minv;
	}
	for(int i=1;i<=k;i++)
	{
		minc=min(minc,c[i]);
		ans+=minc;
		for(int j=1;j<=n;j++)
		{
			minx=min(minx,a[j]);
			ans+=minx;
		}
	}
	cout<<ans%10*10+ans/10;
	return 0;
}
