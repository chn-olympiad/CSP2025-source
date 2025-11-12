#include <cstdio>
#include <algorithm>

typedef long long ll;

const int N = 5007;
const int mod = 998244353;

int n, a[N];
ll Ans;
bool pf = true;

using namespace std;

void dfs (int w, int x, int y, int z)
{
	if (x > n)
	{
		if (w >= 3 && z * 2 < y)
		{
			Ans ++;
			Ans = (Ans == mod ? 0 : Ans);
		}
		return;
	}
	dfs (w + 1, x + 1, y + a[x], max (z, a[x]));
	dfs (w, x + 1, y, z);
}

int main ()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf ("%d", &a[i]);
		if (a[i] != 1)
			pf = false;
	}
	if (pf)
	{
		ll ans = 0;
		for (int i = 3; i <= n; i ++)
		{
			ll comb = 1;
			for (int j = i + 1; j <= n; j ++)
			{
				comb *= j;
				comb /= j - i;
				comb %= mod;
			}
			ans += comb;
			ans %= mod;
		}
		printf ("%lld", ans);
	}
	else
	{
		dfs (0, 1, 0, 0);
		printf ("%lld", Ans);
	}
	return 0;
}
