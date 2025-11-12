#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;

ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const ll N = 3e5;

struct node
{
	ll a, b, c, d;
} a[N + 5];

struct node1
{
	ll val, id;
	bool operator<(const node1 &cmp)const
	{
		return val < cmp.val;
	}
} tmp[N + 5];

bool vis[N + 5];

void solve()
{
	memset(vis, 0, sizeof(vis));
	ll n = read();
	ll ans = 0;
	ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (ll i = 1; i <= n; i++)
	{
		a[i].a = read(), a[i].b = read(), a[i].c = read();
		if (a[i].a >= a[i].b && a[i].a >= a[i].c)
		{
			ans += a[i].a;
			a[i].d = 1;
			cnt1++;
		}
		else if (a[i].b >= a[i].a && a[i].b >= a[i].c)
		{
			ans += a[i].b;
			a[i].d = 2;
			cnt2++;
		}
		else
		{
			ans += a[i].c;
			a[i].d = 3;
			cnt3++;
		}
	}
	if (cnt1 > n / 2)
	{
		ll tot = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (a[i].d == 1)
			{
				tmp[++tot] = {a[i].a - a[i].b, i};
				tmp[++tot] = {a[i].a - a[i].c, i};
			}
		}
		sort(tmp + 1, tmp + tot + 1);
		ll tot1 = 0;
		for (ll i = 1; i <= tot; i++)
		{
			if (tot1 >= cnt1 - n / 2)
			{
				break;
			}
			if (!vis[tmp[i].id])
			{
				tot1++;
				ans -= tmp[i].val;
				vis[tmp[i].id] = 1;
			}
		}
	}
	else if (cnt2 > n / 2)
	{
		ll tot = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (a[i].d == 2)
			{
				tmp[++tot] = {a[i].b - a[i].a, i};
				tmp[++tot] = {a[i].b - a[i].c, i};
			}
		}
		sort(tmp + 1, tmp + tot + 1);
		ll tot2 = 0;
		for (ll i = 1; i <= tot; i++)
		{
			if (tot2 >= cnt2 - n / 2)
			{
				break;
			}
			if (!vis[tmp[i].id])
			{
				tot2++;
				ans -= tmp[i].val;
				vis[tmp[i].id] = 1;
			}
		}
	}
	else if (cnt3 > n / 2)
	{
		ll tot = 0;
		for (ll i = 1; i <= n; i++)
		{
			if (a[i].d == 3)
			{
				tmp[++tot] = {a[i].c - a[i].b, i};
				tmp[++tot] = {a[i].c - a[i].a, i};
			}
		}
		sort(tmp + 1, tmp + tot + 1);
		ll tot3 = 0;
		for (ll i = 1; i <= tot; i++)
		{
			if (tot3 >= cnt3 - n / 2)
			{
				break;
			}
			if (!vis[tmp[i].id])
			{
				tot3++;
				ans -= tmp[i].val;
				vis[tmp[i].id] = 1;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t = read();
	while (t--)
	{
		solve();
	}
	return 0;
}
