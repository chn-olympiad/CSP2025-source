#include <bits/stdc++.h>
using namespace std;

int a[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	bool fa = 1, fb = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1)
		{
			fa = 0;
			if(a[i] != 0)
			{
				fb = 0;
			}
		}
	}
	if(fa)
	{
		cout << n / 2;
	}
	else if(fb)
	{
		int x = 0, cnt = 0, e = 0;
		bool f = 1;
		for(int i = 1; i <= n; i++)
		{
			if(f == 1)
			{
				x = a[i];
				f = 0;
			}
			else
			{
				x = (x != a[i]);
			}
			if(x == k || (a[i] != a[i - 1]) == k && i - 1 != e || a[i] == k)
			{
				cnt++;
				f = 1;
				e = i;
			}
		}
		cout << cnt;
	}
	else
	{
		int x = 0, cnt = 0, e = 0;
		bool f = 1;
		for(int i = 1; i <= n; i++)
		{
			if(f == 1)
			{
				x = a[i];
				f = 0;
			}
			else
			{
				x = (x ^ a[i]);
			}
			if(x == k || (a[i] ^ a[i - 1]) == k && i - 1 != e || a[i] == k)
			{
				cnt++;
				f = 1;
				e = i;
			}
		}
		cout << cnt;
	}
	return 0;
}
