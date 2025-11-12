#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(1);
	a[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n * m; i++)
	{
		int c;
		cin >> c;
		a.push_back(c);
	}
	int x = a[1];
	sort(a.begin() + 1, a.end(), cmp);
	int y = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x)
		{
			y = i;
			break;
		}
	}
	if (y % n == 0)
	{
		cout << y / n << " ";
		if ((y / n) & 1)
		{
			cout << n;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout << y / n + 1 << " ";
		if ((y / n + 1) & 1)
		{
			cout << y % n;
		}
		else
		{
			cout << n - y % n + 1;
		}
	}
	return 0;
}
