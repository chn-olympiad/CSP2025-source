#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, T;
string s[N], t[N];

void solve()
{
	while (T -- )
	{
		string a, b;
		cin >> a >> b;
		int res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			for (int j = 0; j < a.size(); j ++ )
			{
				if (j + s[i].size() > a.size()) break;
				bool flag = 0;
				for (int k = 0; k < s[i].size(); k ++ )
				{
					if (a[j + k] != s[i][k])
					{
						flag = 1;
						break;
					}
				}
				if (!flag)
				{
					string c = a;
					for (int k = 0; k < s[i].size(); k ++ ) c[j + k] = t[i][k];
					if (c == b) res ++ ;
					j = j + s[i].size() - 1;
				}
			}
		}
		cout << res << "\n";
	}
}

int k[N], kk[N];

void solve2()
{
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 0; j < s[i].size(); j ++ )
		{
			if (s[i][j] == 'b')
			{
				k[i] = j;
			}
			if (t[i][j] == 'b')
			{
				kk[i] = j;
			}
		}
	}
	while (T -- )
	{
		string a, b;
		cin >> a >> b;
		int p = 0, q = 0, res = 0;
		for (int i = 0; i < a.size(); i ++ )
		{
			if (a[i] == 'b')
			{
				p = i;
				break;
			}
		}
		for (int i = 0; i < b.size(); i ++ )
		{
			if (b[i] == 'b')
			{
				q = i;
				break;
			}
		}
		int la = a.size();
		for (int i = 1; i <= n; i ++ )
		{
			if (p >= k[i] && (la - p) >= (s[i].size() - k[i]))
			{
				if (p - q == k[i] - kk[i]) res ++ ;
			}
		}
		cout << res << '\n';
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> T;
	for (int i = 1; i <= n; i ++ ) cin >> s[i] >> t[i];
	if (n <= 100 && T <= 100) solve();
	else solve2();
	return 0;
}


