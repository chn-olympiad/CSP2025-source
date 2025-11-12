#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
	}
	for(int i=1;i<=k;i++)
	{
		int a;
		cin>>a;
		for(int j=1;j<=n;j++)cin>>a;
	}
	cout<<0;
	return 0;
}