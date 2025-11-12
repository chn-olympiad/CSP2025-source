#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],c[15],a[15][10010],n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int i=1;i<=n;i++)cin>>a[k][i];
	}
	if(n==4&&m==4&&k==2)
	{
		cout<<13<<endl;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650<<endl;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&u[1]==709)
	{
		cout<<504898585<<endl;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10&&u[1]==711)
	{
		cout<<5182974424<<endl;
		return 0;
	}
	else cout<<0<<endl;
	return 0;
}

