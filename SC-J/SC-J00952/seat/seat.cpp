#include <bits/stdc++.h>
using namespace std;

int a[110];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 1; i <= sum; i++)
		cin >> a[i];
	int xr = a[1];
	sort(a+1, a+sum+1);
	int h = 1, l = 1, d = 0;
	for (int i = sum; i >= 1; i--)
	{
		if (xr == a[i])
		{
			cout << l << ' ' << h << endl;
			return 0;
		}
		if (d == 0)
		{
			if (h < n) h++;
			else l++, d = 1;
		}
		else
		{
			if (h > 1) h--;
			else l++, d = 0;
		}
	}
	return 0;
}