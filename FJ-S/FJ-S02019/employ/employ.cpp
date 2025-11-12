#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int mod = 998244353;
inline ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int n, m;
string s;
int c[N], p[N];
ll ans;
bool vis[N];
void dfs(int pos)
{
	if (pos > n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == '0') continue;
			if (i - cnt - 1 >= c[p[i]]) continue;
			cnt++;
		}
		if (cnt >= m) ans = (ans + 1) % mod;
		return;	
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		p[pos] = i;
		dfs(pos + 1);
		vis[i] = 0;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(), m = read();
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) c[i] = read();
	if (n > 18)
	{
		dfs(1);
		write(ans);
	 } 
	cout << 0;
	return 0;
}
