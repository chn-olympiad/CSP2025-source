#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],pos,x,y,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (a[i]>a[1])
		{
			pos++;
		}
	}
	x=1;
	y=1;
	d=1;
	for (int i=1;i<=pos;i++)
	{
		x+=d;
		if (x==0)
		{
			x=1;
			y++;
			d=-d;
		}
		if (x==n+1)
		{
			x=n;
			y++;
			d=-d;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
