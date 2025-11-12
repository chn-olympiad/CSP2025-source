#include <bits/stdc++.h>
using namespace std;
int a[500005], n, f, k, s;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			f = 1;
		}
	} 
	if (!f && !k)
	{
		cout << n / 2;
	 	return 0;
	}
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1) 
			{
				s++;
			}
		}
	}
	else if (k == 0)
	{
		f = 0;
		for (int i = 1; i <= n; i++)
		{
			if (f)
			{
				f = 0;
				continue;
			}
			else if (a[i] == 0) 
			{
				s++;
			}
			else if (a[i] == 1 && a[i + 1] == 1)
			{
				s++;
				f = 1;
			}
		}
	}
	cout << s;
}
