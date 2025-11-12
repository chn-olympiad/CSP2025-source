#include<bits/stdc++.h>
using namespace std;
const long long w = 998244353;
long long n, m, g, h, s = 1, b[105], c[300005], f[105][300005];
char a[105];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		s = s * i % w;
		if (a[i] == '0')
		{
			g = 1;
		}
	}
	for (long long i = 1; i <= n; i++)
	{
		cin >> b[i];
		if (b[i] == 0)
		{
			h++;
		}
	}
	f[0][0] = 1;
	for (long long i = 0; i < (1 << n); i++)
	{
		for (long long j = 1; j <= n; j++)
		{
			if (i & (1 << (j - 1)))
			{
				continue;
			} 
			c[i | (1 << (j - 1))] = c[i] + 1;
		}
	}
	for (long long i = 0; i < (1 << n); i++)
	{
		for (long long j = 1; j <= n; j++)
		{
			if (i & (1 << (j - 1)))
			{
				continue;
			} 
			for (long long k = 0; k <= n; k++)
			{
				f[k + (b[j] <= k || a[c[i] + 1] == '0')][i | (1 << (j - 1))] = (f[k][i] + f[k + (b[j] <= k || a[c[i] + 1] == '0')][i | (1 << (j - 1))]) % w;
			}
		}
	}
	for (long long i = n - m + 1; i <= n; i++)
	{
		s = (s - f[i][(1 << n) - 1] + w) % w;
	}
	cout << s;
	return 0;
}
