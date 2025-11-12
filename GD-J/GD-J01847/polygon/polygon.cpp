#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const ll mod = 998244353;
const int N = 5e3 + 5;
int a[N];
int n, maxn;
int dp[N][N << 1];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), maxn = max(maxn, a[i]);
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= maxn * 2 + 1; j++)
		{
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			dp[i + 1][min(j + a[i + 1], maxn * 2 + 1)] = (dp[i + 1][min(j + a[i + 1], maxn * 2 + 1)] + dp[i][j]) % mod;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i] * 2 + 1; j <= (i < n ? a[i + 1] * 2 : maxn * 2 + 1); j++)
		{
			ans = (ans + dp[i][j]) % mod;
		}
	}
	write(ans);	
	return 0;
}

