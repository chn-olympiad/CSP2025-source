#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int Q = 2e5 + 5, N = 25e5 + 5, mod = 0, base = 19;
int hs1[Q], hs2[Q], hs[N], pw[N], n, q, lt[Q];
int gh(int l, int r, int hs[])
{
	return hs[r] - hs[l - 1] * pw[r - l + 1];
}

void calc_c(string s)
{
	int cnt = 0, lens = s.size();
	s = "%" + s;
	for(int i = 1; i <= lens; i++)
		hs[i] = hs[i - 1] * base + (s[i] - 'a' + 1);
	return ;
}

int calc(string t)
{
	int cnt = 0;
	for(int i = 0; i < t.size(); i++)
		cnt = cnt * base + (t[i] - 'a' + 1);
	return cnt;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	for(int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * base;
	for(int i = 1; i <= n; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int len1 = s1.size(), len2 = s2.size();
		s1 = "%" + s1, s2 = "%" + s2;
		for(int j = 1; j <= len1; j++)
			hs1[i] = hs1[i] * base + (s1[j] - 'a' + 1);
		for(int j = 1; j <= len2; j++)
			hs2[i] = hs2[i] * base + (s2[j] - 'a' + 1);
		lt[i] = len1;
	}
	while(q--)
	{
		int cnt = 0;
		string s, t;
		cin >> s >> t;
		calc_c(s);
		int nt = calc(t);
		int lens = s.size();
		s = "%" + s;
		for(int i = 1; i <= lens; i++)
			for(int j = 1; j <= n; j++)
			{
				if(i + lt[j] - 1 > lens)
					continue;
				int zh = gh(i, i + lt[j] - 1, hs);
				if(zh == hs1[j] && hs[lens] - zh * pw[i - 1] + hs2[j] * pw[i - 1] == nt)
					cnt++;
			}
		cout << cnt << '\n';
	}
	return 0;
}
