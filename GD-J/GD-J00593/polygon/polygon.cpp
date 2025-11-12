#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
int a[5007], cnt = 0, n;
bool flag[5007];

bool check()
{
	int sum = 0, c = 0, maxn = -1;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i] * flag[i];
		if (flag[i])
		{
			maxn = max(maxn, a[i]);
			c++;
		}
	}
	return sum > 2 * maxn && c >= 3;
}

void dfs(int step)
{
	if (step > n)
	{
		if (check()) cnt++;
		return;
	}
	flag[step] = false;
	dfs(step + 1);
	flag[step] = true;
	dfs(step + 1);
}

long long qpow(int b)
{
	long long m = 1, a = 2;
	while (b > 0)
	{
		if (b & 1) m = m * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return m;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int maxn = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	if (n <= 30)
	{
		cnt = 0;
		dfs(1);
		cout << cnt % p;
		return 0;
	}
	else if (maxn == 1)
	{
		cout << ((qpow(n) - n - (n - 1) * n / 2 - 1) + 1ll * 10 * p) % p;
		return 0;
	}
	return 0;
}
