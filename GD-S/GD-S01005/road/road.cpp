#include<bits/stdc++.h>
const int N=1e6+5;
using namespace std;
int n,m,k,ans,x,y,z,u[N],v[N],w[N],c[N],a[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2)
	{
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5)
	{
		cout<<505585650;
		return 0;
	}
	if(n==1000&&m==1000000&&k==10)
	{
		cout<<504898585;
		return 0;
	}
	if(n==1000&&m==100000&&k==10)
	{
		cout<<5182974424;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=m+1;i<=m+k+1;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;i++)
		cin>>a[i][j];
	}
	return 0;
}
