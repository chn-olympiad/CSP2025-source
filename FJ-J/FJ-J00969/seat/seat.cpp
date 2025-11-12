#include <bits/stdc++.h>
using namespace std;
int n, m, a[500], c, x, y;
int main()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n*m; i++)
		cin >> a[i];
	c=a[1];
	sort(a+1, a+n*m+1);
	for (int i=1; i<=n*m; i++)
	{
		if (a[i]==c)
		{
			c=n*m-i+1;
			break;
		}
	}
	x=c/n;
	if (c%n!=0)
		x++;
		
	if (x%2==1)
		y=c%n;
	else
		y=n-c%n+1;
	
	
	y=y%n;
	if (y==0)
		y=n;
	cout << x << " " << y;
	return 0;
}

