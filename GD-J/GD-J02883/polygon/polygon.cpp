#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 5e3 + 10, mod = 998244353;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9'){ if(ch == '-'){ w = -1;} ch = getchar();}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n;
int a[N];
int dp[N * N][3];
//map<int, bool > vis;
//set<int> v;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	int s = 0, mx = 0;
	for(int i = 1; i <= n; i++) a[i] = read(), mx = max(mx, a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0, lst = 0;
	for(int i = 1; i <= n; i++)
	{
//		cout << i << endl;
//		for(int j = a[i] + 1; j <= n * mx; j++)
//		{
////			cout << i << " " << j << " " << dp[j][2] << " " << dp[j][1] << endl;
//			(ans += (dp[j][2] + dp[j][1]) % mod) %= mod;
//		}
		(ans += lst) %= mod;
		lst = 0;
		for(int k = s; k; k--)
		{
			for(int op = 0; op < 2; op++)
			{
				(dp[k + a[i]][op + 1] += dp[k][op]) %= mod;
//				printf("dp[%d + %d][%d] += dp[%d][%d]   ->   +%d=%d\n", k, a[i], op + 1, k, op, dp[k][op], dp[k + a[i]][op + 1]);
			}
			(dp[k + a[i]][2] += dp[k][2]) %= mod;
			if(k + a[i] > a[i + 1])
			{
				(lst += (dp[k + a[i]][1] + dp[k + a[i]][2]) % mod) %= mod;
			}
		}
		dp[a[i]][0]++;
//		if(!vis[a[i]]) v.insert(a[i]), vis[a[i]] = 1;
		dp[a[i]][0] %= mod;
		s += a[i];
	}
	printf("%lld\n", ans);
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

it's ok noooo
bu zheng le
*/









