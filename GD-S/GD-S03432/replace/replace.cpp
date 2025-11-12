#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string s1[N], s2[N];
string t1[N], t2[N];
int n, q;

bool chk(string s)
{
	int cnta = 0, cntb = 0;
	for (auto i : s)
	{
		if (i == 'a') cnta++;
		if (i == 'b') cntb++;
	}
	return cnta == s.size() - 1 && cntb == 1;
}
int findb(string s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'b')
			return i;
}
void solve1()
{
	for (int i = 1; i <= q; i++)
	{
		int p1 = findb(t1[i]), p2 = findb(t2[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int ps1 = findb(s1[i]), ps2 = findb(s2[i]);
			if (ps2 - ps1 + 1 == p2 - p1 + 1)
			{
				if (ps1 > ps2) swap(ps1, ps2);
				ans += ps1 * (s2[i].size() - ps2);
			}
		}
		cout << ans << '\n';
	}
	
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool flag = true;
	for (int i = 1; i <= n; i++) 
	{
		cin >> s1[i] >> s2[i];
		if (!chk(s1[i]) || !chk(s2[i])) flag = false;
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> t1[i] >> t2[i];
		if (!chk(t1[i]) || !chk(t2[i])) flag = false;
	}
	if (flag) solve1();
	return 0;
}
