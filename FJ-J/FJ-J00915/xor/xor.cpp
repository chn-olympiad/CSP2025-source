#include <bits/stdc++.h>
using namespace std;
long long xo(long long a, long long b)
{
	long long c;
	int x[25] = {0}, y[25] = {0}, z[25] = {0};
	int m = 1, n = 1;
	while (a > 0)
	{
		x[m++] = a % 2;
		a /= 2;
	}
	while (b > 0)
	{
		y[n++] = b % 2;
		b /= 2;
	}
	for (int i = 1; i <= 20; i++)
	{
		if (x[i] == y[i])
		{
			z[i] = 0;	
		}
		else
		{
			z[i] = 1;
		}
	}
	for (int i = 1, j = 1; i <= 18; i++, j *= 2)
	{
		c += z[i] * j;
	}
	return c;
}
long long n, a[105], k, sum, num;
bool flag = 1;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag)
		{
			sum = a[i];
			flag = 0;
		}
		else
		{
			sum = xo(sum, a[i]);
		}
		if (sum == k)
		{
			flag = 1;
			num++;
		}
	}
	cout << num;
}
