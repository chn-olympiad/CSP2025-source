#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

namespace IO
{
	char ch;
	inline void read() {}
	template<class T1, class... T2>
	inline void read(T1& num1, T2&... num2)
	{
		num1 = 0; ch = getchar();
		for (; !isdigit(ch); ch = getchar());
		for (; isdigit(ch); ch = getchar())
			num1 = num1 * 10 + (ch ^ '0');
		read(num2...);
	}
}
using IO::read;

const int N = 19;
const int mod = 998244353;

int n, m, lim, a[N], c[N];
int f[1 << N][N], ans, pcnt[1 << N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%1d", &a[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &c[i]);
	}
	f[0][0] = 1;
	lim = (1 << n) - 1;
	for (int s = 1; s <= lim; ++s)
	{
		pcnt[s] = pcnt[s >> 1] + (s & 1);
		for (int i = 0; i < n; ++i)
		{
			if (s >> i & 1)
			for (int k = 0; k < n; ++k)
			{
				if (a[pcnt[s]] == 0)
				{
					f[s][k + 1] = (f[s][k + 1] + f[s ^ (1 << i)][k]) % mod;
				}
				else
				{
					if (k >= c[i + 1])
					{
						f[s][k + 1] = (f[s][k + 1] + f[s ^ (1 << i)][k]) % mod;
					}
					else
					{
						f[s][k] = (f[s][k] + f[s ^ (1 << i)][k]) % mod;
					}
				}
			}
		}
	}
	for (int i = n - m; i >= 0; --i)
	{
		ans = (ans + f[lim][i]) % mod;
	}
	printf("%d", ans);
	return 0;
}
