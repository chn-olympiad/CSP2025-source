#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
typedef long long ll;
inline int read() {int x; return scanf("%d", &x), x;}
namespace solve
{
	const int N = 2e5;
	const int M = 1e7;
	char s[M + 5], t[M + 5];
	int son[M + 5][26], cnt[M + 5], root[M + 5], type[M + 5], tot;
	inline void insert(char s[], char t[])
	{
		int m = std :: strlen(s + 1);
		int l = 1, r = m;
		while (l <= m && s[l] == t[l]) l ++ ;
		if (l > m) return;
		while (s[r] == t[r]) r -- ;
		int *u = &root[0];
		if (!*u) *u = ++ tot, type[tot] = 1;
		for (int i = l; i <= r; i ++ )
		{
			u = &son[*u][s[i] - 'a'];
			if (!*u) *u = ++ tot, type[tot] = 1;
		}
		u = &root[*u];
		if (!*u) *u = ++ tot, type[tot] = 2;
		for (int i = l; i <= r; i ++ )
		{
			u = &son[*u][t[i] - 'a'];
			if (!*u) *u = ++ tot, type[tot] = 2;
		}
		u = &root[*u];
		if (!*u) *u = ++ tot, type[tot] = 3;
		for (int i = l - 1; i >= 1; i -- )
		{
			u = &son[*u][s[i] - 'a'];
			if (!*u) *u = ++ tot, type[tot] = 3;
		}
		u = &root[*u];
		if (!*u) *u = ++ tot, type[tot] = 4;
		for (int i = r + 1; i <= m; i ++ )
		{
			u = &son[*u][s[i] - 'a'];
			if (!*u) *u = ++ tot, type[tot] = 4;
		}
		cnt[*u] ++ ;
	}
	int res[N + 5];
	struct node
	{
		std :: string s;
		int id;
	};
	std :: vector<node> req[M + 5];
	bool vis[M + 5];
	inline void query(char s[], char t[], int id)
	{
		int m = std :: strlen(s + 1);
		int l = 1, r = m;
		while (s[l] == t[l]) l ++ ;
		while (s[r] == t[r]) r -- ;
		int *u = &root[0];
		if (!*u) return;
		for (int i = l; i <= r; i ++ )
		{
			u = &son[*u][s[i] - 'a'];
			if (!*u) return;
		}
		u = &root[*u];
		if (!*u) return;
		for (int i = l; i <= r; i ++ )
		{
			u = &son[*u][t[i] - 'a'];
			if (!*u) return;
		}
		u = &root[*u];
		if (!*u) return;
		for (int i = l - 1; i >= 0; i -- )
		{
			vis[*u] = 1;
			if (!i || !son[*u][s[i] - 'a']) break;
			u = &son[*u][s[i] - 'a'];
		}
		std :: string hy;
		for (int i = r + 1; i <= m; i ++ ) hy += s[i];
		req[*u].push_back({hy, id});
	}
	int rt;
	void modify(int u, int &v, int t)
	{
		if (!v) v = ++ tot;
		cnt[v] += t * cnt[u];
		for (int i = 0; i < 26; i ++ )
		{
			if (!son[u][i]) continue;
			modify(son[u][i], son[v][i], t);
		}
	}
	void dfs(int u)
	{
		modify(root[u], rt, 1);
		while (req[u].size())
		{
			std :: string s = req[u].back().s; int id = req[u].back().id; req[u].pop_back();
			res[id] = cnt[rt];
			for (int i = 0, u = rt; i < s.length(); i ++ )
			{
				if (!son[u][s[i] - 'a']) break;
				u = son[u][s[i] - 'a'];
				res[id] += cnt[u];
			}
		}
		for (int i = 0; i < 26; i ++ )
		{
			if (!vis[son[u][i]]) continue;
			dfs(son[u][i]);
		}
		modify(root[u], rt, -1);
	}
	int main()
	{
		int n = read(), q = read();
		for (int i = 1; i <= n; i ++ )
		{
			scanf("%s %s", s + 1, t + 1);
			insert(s, t);
		}
		for (int i = 1; i <= q; i ++ )
		{
			scanf("%s %s", s + 1, t + 1);
			query(s, t, i);
		}
		for (int i = 1; i <= tot; i ++ ) if (type[i] == 2 && root[i] && vis[root[i]]) dfs(root[i]);
		for (int i = 1; i <= q; i ++ ) printf("%d\n", res[i]);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	int T = 1;
	while (T -- ) solve :: main();
	return 0;
}