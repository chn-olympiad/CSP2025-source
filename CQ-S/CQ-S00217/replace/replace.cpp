#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
//typedef long long ll;
typedef pair <int, int> pii;
int base = 131, mod = 1e9 + 7;
string s[200010][4];
vector <int> h[200010][2];
int b[5000010], ll[200010], rr[200010];
int h1[5000010], h2[5000010];

signed main()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin.tie (0);
	ios::sync_with_stdio (false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		for (int j = 0; j < s[i][1].size (); j++)
			if (s[i][1][j] != s[i][2][j])
			{
				ll[i] = j;
				break;
			}
		for (int j = s[i][1].size () - 1; j >= 0; j--)
			if (s[i][1][j] != s[i][2][j])
			{
				rr[i] = j;
				break;
			}
		s[i][3] = s[i][1].substr (ll[i], rr[i] - ll[i] + 1);
		h[i][1].push_back (s[i][1][0] - 'a'), h[i][2].push_back (s[i][2][0] - 'a');
		for (int j = 1; j < s[i][1].size (); j++)
			h[i][1].push_back (0), h[i][1][j] = (h[i][1][j - 1] * base + s[i][1][j] - 'a') % mod,
			h[i][2].push_back (0), h[i][2][j] = (h[i][2][j - 1] * base + s[i][2][j] - 'a') % mod;
	}
	b[0] = 1;
	for (int i = 1; i <= 5e6; i++)
		b[i] = b[i - 1] * base % mod;
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size () != t2.size ())
		{
			puts ("0");
			continue;
		}
		int l = 0, r = t1.size () - 1;
		for (int i = 0; i < t1.size (); i++)
			if (t1[i] != t2[i])
			{
				l = i;
				break;
			}
		for (int i = t1.size () - 1; i >= 0; i--)
		{
			if (t1[i] != t2[i])
			{
				r = i;
				break;
			}
		}
		h1[0] = t1[0] - 'a', h2[0] = t2[0] - 'a';
		for (int i = 1; i < t1.size (); i++)
			h1[i] = (h1[i - 1] * base + t1[i] - 'a'), h2[i] = (h2[i - 1] * base + t2[i] - 'a');
		string t = t1.substr (l, r - l + 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (t == s[i][3])
			{
				if (l < ll[i] || t1.size () - r < s[i][1].size () - rr[i]) continue;
				int L = l - ll[i], R = r + s[i][1].size () - rr[i];
//				if (((h1[r] - h1[l - 1] * b[r - l + 1] % mod) % mod + mod) % mod == h[i][1] && )
				if (s[i][1].substr (ll[i], rr[i]) == t1.substr (L, R) && s[i][2].substr (ll[i], rr[i]) == t2.substr (L, R)) cnt++; 
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}

