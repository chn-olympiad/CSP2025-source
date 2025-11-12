#include <bits/stdc++.h>
#define ll long long
#define fi  first
#define se second
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9')
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n, m;
string s;
int a[N], now[N];
ll ans;
bool use[N];
void dfs(int u)
{
	if(u == n + 1)
	{
		int pas = 0;
		for(int i = 1; i <= n; i++)
		{
			if((i - 1 - pas) >= now[i]) continue;
			pas += (s[i] == '1');
		}
		ans += (pas >= m);
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!use[i])
		{
			now[u] = a[i], use[i] = 1;
			dfs(u + 1);
			now[u] = 0, use[i] = 0;
		}
	}
}
ll A(int a, int b)
{
	ll res = 1;
	for(int i = 1; i <= b; i++) (res = res * (a - i + 1) % mod);
	return res;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	while(1)
//	{
//		int x = read(), y = read();
//		cout << A(x, y) << endl;
//	}
	n = read(), m = read();
	cin >> s;
	s = "!" + s;
	for(int i = 1; i <= n; i++) a[i] = read();
	bool fl = 1;
	for(int i = 1; i <= n; i++) fl &= (s[i] == '1');
	int all = n;
	for(int i = 1; i <= n; i++) all -= (a[i] == 0);
	if(n <= 18)
	{
		dfs(1);
		printf("%lld\n", ans);
		return 0;
	}
	if(m == n)
	{
		if(fl && all == n) printf("%lld\n", A(n, n));
		else puts("0");
		return 0;
	}
	if(fl)
	{
//		cout << all << endl;
		if(all < m) puts("0");
		else printf("%lld\n", A(all, all));
		return 0;
	}
	if(m == 1)
	{
		int pos = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '1')
			{
				pos = i;
				break;
			}
		}
		int all = n;
		for(int i = 1; i <= n; i++) all -= (a[i] == 0);
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] >= pos)
			{
				(ans += A(all - 1, all - 1)) %= mod;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}
/*
20pts
nooooo
*/
