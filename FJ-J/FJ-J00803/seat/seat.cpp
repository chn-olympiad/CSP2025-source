#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	b = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i] == b)
		{
			b = i;
			break;
		}
	}
	int x, y;
	if (b % n)
	{
		x = b / n + 1;
		if (x % 2)
		{
			y = b % n;
		}
		else
		{
			y = m - b % n + 1;
		}
	}
	else
	{
		x = b / n;
		if (x % 2)
		{
			y = n;
		}
		else
		{
			y = 1;
		}
	}
	cout << x << " " << y;
	return 0;
}
