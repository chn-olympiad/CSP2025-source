#include <bits/stdc++.h>
using namespace std;

//inline int read()
//{
//	// int f = 1?
//	int res = 0; char ch = getchar();
//	while (!isdigit(ch)) ch = getchar();
//	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
//	return res;
//}
//inline void read_str(char *s)
//{
//	int p = 0; char ch = getchar();
//	while (!islower(ch)) ch = getchar();
//	while (islower(ch)) s[p++] = ch, ch = getchar();
//	s[p] = '\0';
//}

const int MAXN = 2e5 + 10, MAXM = 2.5e6 + 10;

int n, q; string s[MAXN][2], q0, q1;

map<int, int> ch2[MAXM]; // <ch, num>.
int node_cnt = 0, fail[MAXM][23], dep[MAXM], w[MAXM][23];

inline int get_ch_num(char a, char b) {return (a - 'a') * 26 + (b - 'a');}

inline void build1()
{
	vector<pair<int, int> > qu, qu_tmp; // <str_id, node_num>.
	
	for (int i = 1; i <= n; i++) qu.emplace_back(make_pair(i, 0));
	for (int d = 0; qu.size(); d++)
	{
		for (auto u : qu)
		{
			dep[u.second] = d;
			if (d >= (int)s[u.first][0].size()) {w[u.second][0]++; continue;}
			int ch = get_ch_num(s[u.first][0][d], s[u.first][1][d]);
			if (ch2[u.second].find(ch) == ch2[u.second].end())
				ch2[u.second][ch] = ++node_cnt;
			qu_tmp.emplace_back(u.first, ch2[u.second][ch]);
		}
		qu = qu_tmp, qu_tmp.clear();
	}
}

inline void build2()
{
	vector<int> qu, qu_tmp;
	
	for (auto u : ch2[0])
	{
		qu.emplace_back(u.second);
		for (int i = 1; i < 23; i++)
			fail[u.second][i] = fail[fail[u.second][i - 1]][i - 1],
			w[u.second][i] = w[u.second][i - 1] + w[fail[u.second][i - 1]][i - 1];
	}
	while (qu.size())
	{
		for (auto u : qu)
		{
			for (auto v : ch2[u])
			{
				qu_tmp.emplace_back(v.second);
				int u2 = fail[u][0];
				while (1)
				{
					if (ch2[u2].find(v.first) != ch2[u2].end())
						{fail[v.second][0] = ch2[u2][v.first]; break;}
					if (!u2) break; else u2 = fail[u2][0];
				}
				for (int i = 1; i < 23; i++)
					fail[v.second][i] = fail[fail[v.second][i - 1]][i - 1],
					w[v.second][i] = w[v.second][i - 1] + w[fail[v.second][i - 1]][i - 1];
			}
		}
		qu = qu_tmp, qu_tmp.clear();
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	
	build1(), build2();
//	for (int i = 1; i <= node_cnt; i++) cout << fail[i][0] << " "; cout << "-fail\n";
	
	for (int i = 1; i <= q; i++)
	{
		cin >> q0 >> q1; if (q0.size() != q1.size()) {puts("0"); continue;}
		int now = 0, l = q0.size(), l1 = 0, r1 = 0, res = 0;
		for (int j = 0; j < l; j++) if (q0[j] != q1[j]) {l1 = j; break;}
		for (int j = 0; j < l; j++) if (q0[j] != q1[j]) r1 = j;
		for (int j = 0; j < l; j++)
		{
			int ch = get_ch_num(q0[j], q1[j]);
			while (now && ch2[now].find(ch) == ch2[now].end()) now = fail[now][0];
			if (ch2[now].find(ch) != ch2[now].end()) now = ch2[now][ch];
			
			if (j < r1) continue;
			if (dep[now] < j - l1 + 1) continue;
			
			int u = now;
			for (int k = 23 - 1; k >= 0; k--)
				if (dep[fail[u][k]] >= j - l1 + 1) res += w[u][k], u = fail[u][k];
			res += w[u][0];
		}
		printf("%d\n", res);
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

acm build time complexity: O(idk)
too hard in CSP.
*/
