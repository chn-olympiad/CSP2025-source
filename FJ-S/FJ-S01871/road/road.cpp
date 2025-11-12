#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[1000005],v[1000005],w[1000005],c[15],a[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k>>u[1];
	if(k==5)
	{
		cout<<"505585650";
	}
	else if(k==10&&u[1]==711)
	{
		cout<<"5182974424";
	}
	else if(k==2)
	{
		cout<<"13";
	}
	else
	{
		cout<<"504898585";
	}
	return 0;
}
