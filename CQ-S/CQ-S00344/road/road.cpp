#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","W",stdout);
	int a1,b1,c1,o,p,q,x,y,s=100000,z=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a1>>b1>>c1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>o>>p>>q>>x>>y;
	}
	for(int i=1;i<=n;i++)
	{
		if(a1<s)
		{
			s=a1;
			i++;
		}
		z+=s;
	}
	for(int i=1;i<=n;i++)
	{
		z+=p;
	}
	cout<<z;
	return 0;
}
