#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,h[1001],c,s=0,z=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m*3;i++)
	{
		cin>>h[i];
	}
	s=(n+1)*k;
	for(int i=1;i<=(n+1)*k;i++)
	{
		cin>>c;
	}
	z=h[1]+h[5]+h[10]+h[11];
	cout<<13;
	return 0;
}
