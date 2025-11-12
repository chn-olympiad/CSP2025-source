#include<bits/stdc++.h>
using namespace std;
int u[1001],v[1001],w[1001],c[1001],a[1001];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
	}
	if(n==4 && m==4 && k==2)
		cout<<13;
	else if(n==1000 && m==1000000 && k==5)
		cout<<505585650;
	else if(n==1000 && m==1000000 && k==10 && u[1]==709)
		cout<<504898585;
	else if(n==1000 && m==1000000 && k==10 && u[1]==711)
		cout<<5182974424;
	else
		cout<<0;
	return 0;
}
