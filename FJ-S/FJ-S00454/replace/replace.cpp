#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
string s1[N], s2[N];
unordered_map<string , int> mp;
int cnt, rrd[N];
vector<int> nxt[N], lk[N];
inline vector<int> init(const string& x)
{
	const int len = x.length();
	vector<int> v(len + 5);
	int j = 0;
	v[0] = 0;
	for (int i = 1; i < len; i ++)
	{
		while (j != 0 && x[i] != x[j])
			j = v[j - 1];
		if (x[i] == x[j])
			++ j;
		v[i] = j;
	}
	return v;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s1[i] >> s2[i];
		int ld = -1, rd = -1, l = s1[i].length();
		for (int j = 0; j < l; j ++)
			if (s1[i][j] != s2[i][j])
			{
				if (ld < 0) ld = j;
				rd = j;
			}
		nxt[i] = init(s1[i]);
//		for (int j = 0; j < l; j ++)
//			cout << nxt[i][j] << ' ';
//		cout << '\n';
//		cout << ld << ' ' << rd << '\n';
		if (ld == -1)
			continue;
		rrd[i] = rd;
		string ds1 = string(s1[i].begin() + ld, s1[i].begin() + rd + 1);
		string ds2 = string(s2[i].begin() + ld, s2[i].begin() + rd + 1);
//		pair<string, string> cur = {ds1, ds2};
		string cur = ds1 + " " + ds2;
//		cout << cur << '\n';
		if (!mp.count(cur))
			mp[cur] = ++ cnt;
		lk[mp[cur]].emplace_back(i);
	}
	string t1, t2;
	while (q --)
	{
		cin >> t1 >> t2;
		if (t1.length() != t2.length())
		{
			cout << "0\n";
			continue;
		}
		int ld = -1, rd = 0, l = t1.length();
		for (int i = 0; i < l; i ++)
			if (t1[i] != t2[i])
			{
				if (ld < 0) ld = i;
				rd = i;
			}
//		pair<string, string> cur = {};
		string cur = string(t1.begin() + ld, t1.begin() + rd + 1) + " " + string(t2.begin() + ld, t2.begin() + rd + 1);
		if (!mp.count(cur))
		{
			cout << "0\n";
			continue;
		}
		int d = mp[cur], ans = 0;
		for (int i : lk[d])
			if (s1[i].length() >= rd - ld + 1)
			{
				for (int j = 0, k = 0; j < l && j - k <= ld; j ++)
				{
					while (s1[i][k] != t1[j] && k != 0)
						k = nxt[i][k - 1];
					if (s1[i][k] == t1[j])
						++ k;
					if (k == s1[i].length())
					{
						if (j - k + 1 + rrd[i] == rd)
							++ ans;
						k = nxt[i][k - 1];
					}
				}
					
			}
		cout << ans << '\n';
	}
	return 0;
}
