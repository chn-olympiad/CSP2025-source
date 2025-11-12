#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
inline void print(__int128 x)
{
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + 48);
}
int n, m, c[1005], f[1005];
__int128 ans{};
bool flag = false;
string s;
inline __int128 A(__int128 m, __int128 n)
{
	__int128 ans = 1;
	for (int i = m - n + 1; i <= m; ++i)
		ans *= i;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i{1}; i <= n; ++i)
		cin >> c[i];
	for (int i{}; s[i] != '\0'; ++i)
	{
		f[i + 1] = s[i] - 48;
		if (flag == false && s[i] == 48)
			flag = true;
	}
	if (!flag)
	{
		for (int i = m; i <= n; ++i)
		{
			ans = (ans + A(n, i)) % mod;
		}
		print(ans);
		exit(0);
	}
	stable_sort (c + 1, c + 1 + n);
	int c2[1005];
	ll k = 0;
		for (int i{1}; i <= n; ++i)
			c2[i] = c[i];
	for (int i{1}; i <= n; ++i)
	{	
		if (c2[i] <= 0)
			continue;
		if (f[i] == 1)
		{
			++k;
		}
		else if (f[i] == 0)
		{
			for (int j = i; j <= n; ++j)
			{
				c2[j] -= 1;
			}
		}
	}
	if (k >= m)
		ans++;
	do
	{
		int c1[1005];
		for (int i{1}; i <= n; ++i)
			c1[i] = c[i];
		ll k = 0;
		for (int i{1}; i <= n; ++i)
		{	
			if (c1[i] <= 0)
				continue;
			if (f[i] == 1)
			{
				++k;
			}
			else if (f[i] == 0)
			{
				for (int j = i; j <= n; ++j)
				{
					c1[j] -= 1;
				}
			}
		}
		if (k >= m)
			++ans;
	}while (next_permutation(c + 1, c + 1 + n));
	print(ans % mod);
	return 0;
}
