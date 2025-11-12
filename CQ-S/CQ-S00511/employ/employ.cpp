#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 500 + 10;

const int N = 18;

char a[maxn];

int c[maxn];

const long long mod = 998244353;

long long f[1 << N][N + 1];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", a + 1);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		
		for (int s = (1 << n) - 1; s >= 0; s--) for (int k = 0; k <= n; k++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((s & (1 << j))) continue;
				int _k = k + (a[i] == '0' || k >= c[j]);
				f[s ^ (1 << j)][_k] = (f[s ^ (1 << j)][_k] + f[s][k]) % mod;
			}
			f[s][k] = 0;
		}
	}
	
	long long ans = 0;
	for (int s = 0; s < 1 << n; s++)
	{
		for (int j = 0; j <= n - m; j++)
		{
			ans = (ans + f[s][j]) % mod;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}



}

int main()
{
	wxr::main();
	return 0;
}

