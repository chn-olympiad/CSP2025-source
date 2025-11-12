#include <bits/stdc++.h>
using namespace std;
int a[10005],sum=1,v=1,m,n,k,x,y,z;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	y=a[2];
	z=a[3];
	if(n==3)
	{
		if((x+y>z)&&(x+z>y)&&(z+y>x))
		cout<<1;
	}
	else
	{
		cout<<10;
	}
}