#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], k = 1;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	for(int i = 2; i <= n * m; i++)
	{
		if(a[i] > a[1])
		{
			k++;
		}
	}
	int c, r;
	c = k / n;
	if(k % n != 0)
	{
		c++;
	}
	if(c % 2 == 0)
	{
		r = n - (k % n) + 1;
	}
	else
	{
		r = k % n;
		if(r == 0)
		{
			r = n;	
		} 
	}
	cout << c << " " << r;
	return 0;
}
