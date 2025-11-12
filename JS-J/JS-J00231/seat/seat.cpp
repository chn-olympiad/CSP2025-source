#include <bits/stdc++.h>
using namespace std;
#define int long long
int s[15][15],n,m,x,y,c,r,a[105];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m,y=1;
	for(int i=0;i<x;i++)
		cin>>a[i];
	for(int i=1;i<x;i++)
	{
		if(a[i]>a[0])
			y++;
	}
	c=ceil(1.000000*y/n);
	r=y%n;
	r=(!r)?n:r;
	if(c%2)
	{
		cout<<c<<' '<<r;
	}
	else
	{
		cout<<c<<' '<<(n+1-r);
	}
	return 0;
}
