#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],R,p,x,y;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	R = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if(a[i] == R) 
		{
			p = i;
			break;
		}
	}
	x = 0,y = 1;
	for (int i = 1; i <= p; i++)
	{
		if (y % 2) 
			x++;
		else 
			x--;
		if (x == n + 1) 
		{
			y++;
			x = n;
		}
		else if (x == 0)
		{
			y++;
			x = 1;
		}
	}
	cout << y << " " << x;
	return 0;
}
