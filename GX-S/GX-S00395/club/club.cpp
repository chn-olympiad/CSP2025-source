#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

const int N = 1e5 + 10;
int t, n;
bool pa, pb;

struct node
{
	int f, s, t;
} a[N];

int f, s, tr;
ll ans;
void Dfs(int p, ll sum)
{
	if (p > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (f < n >> 1) f++, Dfs(p + 1, sum + a[p].f), f--;
	if (s < n >> 1) s++, Dfs(p + 1, sum + a[p].s), s--;
	if (tr < n >> 1) tr++, Dfs(p + 1, sum + a[p].t), tr--;
}

bool cmp(node x, node y)
{
	return x.s > y.s;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		pa = pb = true;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].f >> a[i].s >> a[i].t;
			if (a[i].f && a[i].t)
				pa = false;
			if (a[i].s)
				pb = false;
		}
		if (pa)
		{
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n >> 1; i++)
				ans += a[i].s;
			cout << ans << '\n';
			continue;
		}
		f = s = tr = 0;
		Dfs(1, 0);
		cout << ans << '\n';
	}

	return 0;
}

