#include <bits/stdc++.h>
#define w first
#define id second
using namespace std;
typedef long long i64;
typedef double f16;
typedef pair <int, int> pii;

const int N = 1e5 + 10;
int n;

struct StafF
{
	pii v[3];
	void upd ()
	{
		if (v[1].w > v[2].w) swap (v[1], v[2]);
		if (v[0].w > v[1].w) swap (v[0], v[1]);
		if (v[0].w > v[2].w) swap (v[0], v[2]);
		if (v[1].w > v[2].w) swap (v[1], v[2]);
	}
	int max () { return v[2].w - (v[0].w + v[1].w + v[2].w) / 3; }
}; StafF s[N];

int f[205][205][205], f2[205][205];
void Sub_nxx4 ()
{
	memset (f, 0, sizeof (f));
	for (int cur = 1; cur <= n; cur ++)
		for (int i = n / 2; ~i; i --)
			for (int j = min (n - i, n / 2); ~j ; j --)
				for (int k = min (n - i - j, n / 2); ~k; k --)
				{
					if (i) f[i][j][k] = max (f[i][j][k], f[i - 1][j][k] + s[cur].v[0].w);
					if (j) f[i][j][k] = max (f[i][j][k], f[i][j - 1][k] + s[cur].v[1].w);
					if (k) f[i][j][k] = max (f[i][j][k], f[i][j][k - 1] + s[cur].v[2].w);
				}
	int ans = 0;
	for (int i = 0; i <= n / 2; i ++)
		for (int j = 0; j <= n - i; j ++)
		{
			int k = n - i - j;
			if (max ({i, j, k}) > n / 2) continue;
			ans = max (ans, f[i][j][k]);
		}
	cout << ans << '\n';
}

void SubA ()
{
	sort (s + 1, s + 1 + n, [](StafF a, StafF b){ return a.v[0].w > b.v[0].w; });
	i64 ans = 0;
	for (int i = 1; i <= n / 2; i ++)
		ans += s[i].v[0].w;
	cout << ans << '\n';
}

void SubB ()
{
	memset (f2, 0, sizeof (f2));
	for (int cur = 1; cur <= n; cur ++)
		for (int i = n / 2; ~i; i --)
			for (int j = min (n - i, n / 2); ~j ; j --)
			{
				if (i) f2[i][j] = max (f2[i][j], f2[i - 1][j] + s[cur].v[0].w);
				if (j) f2[i][j] = max (f2[i][j], f2[i][j - 1] + s[cur].v[1].w);
			}
	int ans = 0;
	for (int i = 0; i <= n / 2; i ++)
		for (int j = 0; j <= n - i; j ++)
		{
			if (j > n / 2) continue; 
			ans = max (ans, f2[i][j]);
		}
	cout << ans << '\n';
}

void Solve ()
{
	cin >> n;
	bool subA = true, subB = true;
	for (int i = 1, x, y, z; i <= n; i ++)
	{
		cin >> x >> y >> z;
		s[i].v[0] = {x, 0}, s[i].v[1] = {y, 1}, s[i].v[2] = {z, 2};
		subA &= (!y && !z), subB &= (!z);
	}
	if (subB) return SubB (), void ();
	if (n <= 200) return Sub_nxx4 (), void ();
	if (subA) return SubA (), void ();
	for (int i = 1; i <= n; i ++) s[i].upd ();
	sort (s + 1, s + 1 + n, [](StafF a, StafF b)
		{ return a.max () > b.max (); });
	int cnt[3] = {0, 0, 0}; i64 ans = 0;
	for (int i = 1; i <= n; i ++)
	{
		pii c = s[i].v[2]; int pos = 2;
		while (cnt[c.id] >= n / 2) c = s[i].v[(pos + 2) % 3];
		cnt[c.id] ++;
		ans += c.w;
	}
	cout << ans << '\n';
}

int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin.tie (0) -> sync_with_stdio (0);
	int T; cin >> T;
	while (T --) Solve ();
	return 0;
}

/*

*/
