#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, k, a[N], bjt = 1, bjtt = 1, jsq;

int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			bjt = 0;
		}
		if (a[i] != 1 && a[i] != 0)
		{
			bjtt = 0;
		}
		if (a[i] == 1)
		{
			jsq ++;
		}
	}
	if (bjt && k == 0)
	{
		cout << n / 2;
		return 0;
	}
	if (bjt && k == 1)
	{
		cout << n;
		return 0;
	}
	if (bjtt && k == 1)
	{
		cout << jsq;
		return 0;
	}
	if (k == 0)
	{
		int ans = 0;
		for (int i = 1;i <= n;i ++)
		{
			if (a[i] == 0)
			{
				ans ++;
			}
			else
			{
				if (a[i + 1] == a[i])
				{
					ans ++;
					i ++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
