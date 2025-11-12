#include <bits/stdc++.h>
#define int long long
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;
const int N = 1e5 + 5;
int T = 1, n, a[5][N], tmp[5], pos[5][N], ans, m;
bool vis[N];
struct node{int v, id;}d[N << 1];
bool cmp (node a, node b)
	{return a.v > b.v;}
void solve ()
{
	ans = m = 0;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[1][i] >> a[2][i] >> a[3][i];
	memset (tmp, 0, sizeof tmp);
	for (int i = 1; i <= n; ++ i)
	{
		int p = max (a[1][i], a[2][i]);
		p = max (p, a[3][i]);
		if (p == a[1][i])
			pos[1][++ tmp[1]] = i;
		else if (p == a[2][i])
			pos[2][++ tmp[2]] = i;
		else
			pos[3][++ tmp[3]] = i;
		ans += p;
		vis[i] = 0;
	}
	int P = max (tmp[1], max (tmp[2], tmp[3]));
	if (P <= n / 2)
		return cout << ans << '\n', void ();
	int Pos;
	if (P == tmp[1])
		Pos = 1;
	else if (P == tmp[2])
		Pos = 2;
	else
		Pos = 3;
	int len = tmp[Pos];
	for (int i = 1; i <= len; ++ i)
	{
		if (Pos ^ 1)
			d[++ m] = {a[1][pos[Pos][i]] - a[Pos][pos[Pos][i]], i};
		if (Pos ^ 2)
			d[++ m] = {a[2][pos[Pos][i]] - a[Pos][pos[Pos][i]], i};
		if (Pos ^ 3)
			d[++ m] = {a[3][pos[Pos][i]] - a[Pos][pos[Pos][i]], i};
	}
	sort (d + 1, d + m + 1, cmp);
	int cnt = 0, j = 1;
	while (P - cnt > n / 2)
	{
		if (! vis[d[j].id])
		{
			ans += d[j].v;
			vis[d[j].id] = 1;
			++ cnt;
		}
		++ j;
	}
	cout << ans << '\n';
}
signed main ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T --)
		solve ();
	return 0;
}
