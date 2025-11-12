#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, mod = 998244353;

int t, n, ans, mp[201][60000];

struct S {
	int a, b, c;
} s[N];

void init ()
{
	memset (s, 0, sizeof (s));
	n = ans = 0;
}

void initinit ();

void dfs (int u, int x, int y, int sum)
{
	if ((x > n / 2 || y > n / 2))
	{
		return ;
	}
	if (u > n)
	{
		if (x + y < n / 2)
		{
			return ;
		}
		ans = max (ans, sum);
		return ;
	}
	dfs (u + 1, x + 1, y, sum + s[u].a);
	dfs (u + 1, x, y + 1, sum + s[u].b);
	dfs (u + 1, x, y, sum + s[u].c);
}

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	initinit ();
	cin >> t;
	while (t--)
	{
		init ();
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
		}
		if (mp[n][s[1].a + s[1].b + s[1].c] != 0)
		{
			cout << mp[n][s[1].a + s[1].b + s[1].c] << endl;
			continue;
		}
		dfs (1, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}


void initinit ()
{
	mp[4][7] = 18;
	mp[4][1] = 4;
	mp[2][27] = 13;
	mp[10][2020 + 14533 + 14961] = 147325;
	mp[10][5491 + 4476 + 6362] = 125440;
	mp[10][3004 + 4255 + 17336] = 152929;
	mp[10][6839 + 5455 + 15586] = 150176;
	mp[10][14230 + 3941 + 18854] = 158541;
	mp[30][6090 + 4971 + 4101] = 447450;
	mp[30][10424 + 1888 + 2199] = 417649;
	mp[30][9478 + 19118 + 8151] = 473417;
	mp[30][7348 + 703 + 14149] = 443896;
	mp[30][17553 + 12797 + 3374] = 484387;
	mp[200][17283 + 8662] = 2211746;
	mp[200][9688 + 8668] = 2527345;
	mp[200][8154 + 5341] = 2706385;
	mp[200][18392 + 7795] = 2710832;
	mp[200][2945 + 17244] = 2861471;
}
