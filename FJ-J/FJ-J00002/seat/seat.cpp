#include<bits/stdc++.h>
using namespace std;

int n, m, h, l, b[110], k, r, a[20][20];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> b[i];
	}
	r = b[1];
	sort(b + 1, b + n * m + 1);
	reverse(b + 1, b + n * m + 1);
	h = l = 1;
	while (h <= n && l <= m)
	{
		while (h <= n)
		{
			a[h][l] = b[++k];
			if (a[h][l] == r)
			{
				cout << l << " " << h << endl;
				return 0;
			}
			h++;
		}
		h--;
		l++;
		a[h][l] = b[++k];
		if (a[h][l] == r)
		{
			cout << l << " " << h << endl;
			return 0;
		}
		h--;
		while (h >= 1)
		{
			a[h][l] = b[++k];
			if (a[h][l] == r)
			{
				cout << l << " " << h << endl;
				return 0;
			}
			h--;
		}
		h++;
		l++;
		a[h][l] = b[++k];
		if (a[h][l] == r)
		{
			cout << l << " " << h << endl;
			return 0;
		}
		h++;
	}
	return 0;
}
