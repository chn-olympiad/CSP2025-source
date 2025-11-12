#include <bits/stdc++.h>
using namespace std;
int n, m, s[505], c[505], tpa;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i] != 1)
		{
			tpa = 1;
		}
	}
	int qq = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] == 0)
		{
			qq++;
		}
	}
	
	if (tpa == 0)
	{
		long long num1 = 1, num2 = 1;
		for (int i = 1; i <= n-qq; i++)
		{
			num1 = (num1 * i) % 998244353;
		}
		for (int i = 1; i <= qq; i++)
		{
			num2 = (num2 * i) % 998244353;
		}
		long long num = (num1 * num2) % 998244353;
		cout << num;
	}
	return 0;
}
