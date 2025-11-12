#include <bits/stdc++.h>
using namespace std;
const int N = 5001, mod = 998244353;
int n, a[N], ans, f[N * N];
int read()
{
	char c;
	int a = 0;
	while (c = getchar(), !isdigit(c));
	while (isdigit(c))
	{
		a = a * 10 + c - '0';
		c = getchar();
	}
	return a;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (a[i] != 1)
		{
			flag = false;
			break;
		}
	if (flag)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = ans * 2 % mod;
		cout << ((long long)ans - n - n * (n - 1) / 2 % mod - 1 + mod * 2) % mod;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int sum = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		for (int j = a[i] * 2 + 1; j <= sum; j++)
			ans = (ans + f[j - a[i]]) % mod;
		for (int j = sum; j >= a[i]; j--)
			f[j] = (f[j] + f[j - a[i]]) % mod;
	}
	cout << ans;
	return 0;
}
