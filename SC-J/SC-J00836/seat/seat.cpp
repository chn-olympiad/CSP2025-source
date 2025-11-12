#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,num,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if (a[i] >= a[1])
		{
			num++;
		}
	}
	x = num / n;
	if (num % n != 0)
	{
		x++;
	}
	y = (num % n) ? num % n : n;
	if (!(x & 1))
	{
		y = n - y + 1;
	}
	cout << x << " " << y;
	return 0;
}