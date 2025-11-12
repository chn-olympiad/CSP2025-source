#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	x=1,y=1;
	for (int i = 2; i <= n * m; i++)
	{
		cin >> a[i];
		if (a[i] > a[1])
		{
			if (x % 2 == 1)
			{
				if (y == n)
				{
					x += 1;
				} 
				else
				{
					y += 1;
				}
			}
			else
			{
				if (y == 1)
				{
					x += 1;
				}
				else
				{
					y -= 1;
				}
			} 
		} 
	}
	cout << x << " " << y;
	return 0;
}
