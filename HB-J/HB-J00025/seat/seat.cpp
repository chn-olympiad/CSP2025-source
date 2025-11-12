#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],smr;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> smr;
	for (int i=1;i<=n*m-1;i++) cin >> a[i],a[i]=-a[i];
	sort(a+1,a+1+n*m-1);
	int x=1,y=1,dir=1;//0s,1x,2y
	for (int i=1;i<=n*m-1;i++)
	{
		if (dir==0) 
		{
			x--;
			if (x==1) dir=2;
		}
		else if (dir==1) 
		{
			x++;
			if (x==n) dir=2;
		}
		else if (dir==2) 
		{
			y++;
			if (y%2==0) dir=0;
			else dir=1;
		}
		if (-a[i+1]<smr) break;
	}
	cout << y << " " << x;
	return 0;
}
