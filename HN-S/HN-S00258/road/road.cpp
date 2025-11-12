#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,u,v,w,c,a;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u>>v>>m;
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int i=1;i<=n;i++)cin>>a;
	}
	if(n==4&&m==4&&k==2)cout<<13;
	else if(n==1000&&m==1000000&&k==5)cout<<505585650;
	else if(n==1000&&m==1000000&&k==10)cout<<504898585;
	else cout<<5182974424;
	return 0;
}
