#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005], f = 1, sum;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(a, -1, sizeof(a));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			f = 0;
		}
	}
	if (f == 1)
	{
		cout << n / 2;
	}
	else
	{
		if (k == 0)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == 0)
				{
					sum++;
				}
				else if (a[i] == 1 && a[i + 1] == 1)
				{
					i++, sum++;
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i] != a[i + 1] && a[i + 1] != -1)
				{
					i++, sum++;
				}
			}
		}
		cout << sum;
	}
	return 0;
}
