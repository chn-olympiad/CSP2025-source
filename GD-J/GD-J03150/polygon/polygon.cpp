#include <bits/stdc++.h>
#define LL long long

using namespace std;

const LL N = 5e3 + 10;
const LL mod = 998244353;

LL n, a[N];

LL sum;
LL f[N * 105], g[N * 105];

LL res;

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	for (LL i=1; i<=n; i++)
		cin >> a[i];
	
	sort (a+1, a+n+1);
	
	for (LL i=1; i<=n; i++)
		sum += a[i];
	
	f[0] = 1;
	
	for (LL i=1; i<=n; i++)
	{
		for (LL j=sum; j>=a[i]; j--)
		{
			(f[j] += f[j-a[i]]) %= mod;
		}
		
		for (LL j=0; j<=sum; j++)
		{
			if (j < a[i])
				g[j] = f[j];
			else
				g[j] = f[j] - g[j - a[i]];
		
			g[j] = (g[j] % mod + mod) % mod;
		}
		
		for (LL j=a[i]*2+1; j<=sum; j++)
		{
			(res += g[j - a[i]]) %= mod;
		}
	}
	
	cout << res << '\n';
	
	return 0;
}
