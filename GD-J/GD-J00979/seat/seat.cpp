#include<bits/stdc++.h>

using namespace std;

int a[10086];

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rec;
	cin >> n >> m;
	cin >> rec;
	a[1] = rec;
	for (int i = 2;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == rec)
		{
			rec = i;
		}
	}
	int x, y;
	x = rec % n;
	//cout << x << " ";
	y = rec / n + 1;
	//cout << y << " ";
	if (x == 0)
	{
		x += n;
		y--;
	}//cout << y << " " << x << " ";
	if (y % 2 == 0)
	{
		x = n - x + 1;
	}
	cout << y << " " << x;
	return 0;
}
