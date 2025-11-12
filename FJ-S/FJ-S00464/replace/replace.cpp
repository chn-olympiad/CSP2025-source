#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

const ll N = 2e5;

string s[N + 5][3];

map<ull, map<ull, bool>> mp;
ull base = 131;

ull hash1[N + 5];
ull hash2[N + 5];
ull poww[N + 5];

ull calc1(ll l, ll r)
{
	return hash1[r] - hash1[l - 1] * poww[r - l + 1];
}

ull calc2(ll l, ll r)
{
	return hash2[r] - hash2[l - 1] * poww[r - l + 1];
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	poww[0] = 1;
	for (ll i = 1; i <= N; i++)
	{
		poww[i] = poww[i - 1] * base;
	}
	ll n = read(), q = read();
	for (ll i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
		ull ha1 = 0, ha2 = 0;
		for (ll j = 0; j < (ll)s[i][1].size(); j++)
		{
			ha1 = ha1 * base + s[i][1][j];
			ha2 = ha2 * base + s[i][2][j];
		}
		mp[ha1][ha2] = 1;
	}
	while (q--)
	{
		string a, b;
		cin >> a >> b;
		if (a.size() != b.size())
		{
			cout << 0 << endl;
			continue;
		}
		ll ans = 0;
		ll len = a.size();
		for (ll i = 1; i <= len; i++)
		{
			hash1[i] = hash1[i - 1] * base + a[i - 1];
			hash2[i] = hash2[i - 1] * base + b[i - 1];
		}
		for (ll l = 0; l < len; l++)
		{
			for (ll r = l; r < len; r++)
			{
				ull ha12 = calc1(l + 1, r + 1), ha22 = calc2(l + 1, r + 1);
				if (mp[ha12][ha22])
				{
					ull ha11 = calc1(1, l), ha21 = calc2(1, l);
					ull ha13 = calc1(r + 2, len), ha23 = calc2(r + 2, len);
					if (ha11 == ha21 && ha13 == ha23)
					{
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

