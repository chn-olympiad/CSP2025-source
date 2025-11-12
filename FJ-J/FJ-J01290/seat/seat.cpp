#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], r, sum, h, l = 1, s;
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 1;i <= sum;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + sum + 1, cmp);
	for (int i = 1;i <= sum;i++)
	{
		if (a[i] == r)
		{
			s = i;
			break;
		}
	}
	for (int i = 1;i <= sum;i++)
	{
		if ((l - 1) * n + 1 <= s && l * n >= s) break;
		l++;
	}
	if (l % 2 == 0)
	{
		int q = (l - 1) * n + 1;
		h = n - (s - q);
	}
	else
	{
		int q = (l - 1) * n;
		h = s - q;
	}
	cout << l << " " << h;
	return 0;
}

