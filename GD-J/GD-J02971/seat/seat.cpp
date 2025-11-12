#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}
int n,m,a[105],r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
		cin >> a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,dx=1,dy=0;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==r)
		{
			cout << y << ' ' << x;
			break;
		}
		if (x==n)
		{
			if (y%2==1) dx=0,dy=1;
			else dx=-1,dy=0;
		}
		else if (x==1)
		{
			if (y%2==1) dx=1,dy=0;
			else dx=0,dy=1;
		}
		x+=dx,y+=dy;
	}
	return 0;
}
