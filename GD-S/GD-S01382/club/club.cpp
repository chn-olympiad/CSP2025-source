#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) {if (ch == '-') {f = -1;}}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 10) return putchar(x + '0'), void();
	write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 1e5 + 5, inf = -1e18;
int T, n, a[N][4], ans;
bool p[N];
void dfs(int now, int cnt1, int cnt2, int cnt3, int sum)
{
	if (cnt1 > (n >> 1)) return;
	if (cnt2 > (n >> 1)) return;
	if (cnt3 > (n >> 1)) return;
	if (now > n) return ans = max(ans, sum), void();
	dfs(now + 1, cnt1 + 1, cnt2, cnt3, sum + a[now][1]);
	dfs(now + 1, cnt1, cnt2 + 1, cnt3, sum + a[now][2]);
	dfs(now + 1, cnt1, cnt2, cnt3 + 1, sum + a[now][3]);
}
bool A()
{
	for (int i = 1;i <= n;i++)
	{
		if (a[i][2] || a[i][3]) return 0;
	}
	return 1;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--)
	{
		n = read(), ans = inf;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++) a[i][j] = read();
		}
	    if (n <= 30) dfs(1, 0, 0, 0, 0);
  		else
  		{
  			vector<int> vec;
  			for (int i = 1;i <= n;i++) vec.pb(a[i][1]);
  			sort(vec.begin(), vec.end(), greater<int>());
  			ans = 0;
  			for (int i = 0;i < (n << 1);i++) ans += vec[i];
		}
		write(ans), endl;
	}
	return 0;
}
