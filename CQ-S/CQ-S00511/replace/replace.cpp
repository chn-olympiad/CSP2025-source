#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

namespace wxr
{

const int maxm = 5e6 + 10;

char str[2][maxm];

int next[maxm][26];
int fail[maxm], len[maxm], cnt[maxm];

int tot = 0;

struct graph
{
	int cnt = 0, st[maxm], to[maxm], next[maxm], last[maxm];
	void add(int u, int v)
	{
		cnt++, st[cnt] = u, to[cnt] = v, next[cnt] = last[u], last[u] = cnt;
	}
}
g;

int size[maxm], son[maxm], depth[maxm];

void dfs1(int u)
{
	size[u] = 1, son[u] = 0;
	for (int j = g.last[u]; j != 0; j = g.next[j])
	{
		int v = g.to[j];
		
		cnt[v] += cnt[u];
		depth[v] = depth[u] + 1;
		
		dfs1(v);
		
		size[u] += size[v];
		if (son[u] == 0 || size[v] > size[son[u]]) son[u] = v;
	}
}

int dfx = 0, dfn[maxm], top[maxm];

std::pair<int, int> vec[maxm];

void dfs2(int u, int low)
{
	dfn[u] = ++dfx, top[u] = low;
	
	vec[dfn[u]] = {len[u], u};
	
	if (son[u] != 0) dfs2(son[u], low);
	for (int j = g.last[u]; j != 0; j = g.next[j])
	{
		int v = g.to[j];
		if (v != son[u]) dfs2(v, v);
	}
}

int find(int u, int k)
{
	if (vec[dfn[top[u]]].first <= k)
	{
		int i = (int)(std::lower_bound(vec + dfn[top[u]], vec + dfn[u] + 1, std::pair<int, int>{k + 1, 0}) - vec) - 1;
		return vec[i].second;
	}
	else return find(fail[top[u]], k);
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	tot = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[0] + 1);
		scanf("%s", str[1] + 1);
		int m = (int)strlen(str[0] + 1);
		int p = 0;
		for (int j = 1; j <= 2 * m; j++)
		{
			char c = j % 2 == 1 ? str[0][j / 2 + 1] : str[1][j / 2];
			if (next[p][c - 'a'] == 0) next[p][c - 'a'] = ++tot;
			p = next[p][c - 'a'];
		}
		cnt[p]++;
	}
	std::queue<int> queue;
	fail[0] = 1, len[0] = 0;
	queue.push(0);
	while (!queue.empty())
	{
		int u = queue.front();
		queue.pop();
		for (int j = 0; j < 26; j++)
		{
			if (next[u][j] == 0) next[u][j] = next[fail[u]][j];
			else
			{
				int v = next[u][j];
				if (u != 0) fail[v] = next[fail[u]][j];
				else fail[v] = 0;
				len[v] = len[u] + 1;
				queue.push(v);
			}
		}
	}
	
	for (int i = 1; i <= tot; i++) g.add(fail[i], i);
	dfs1(0);
	dfs2(0, 0);
	
	for (int i = 1; i <= q; i++)
	{
		scanf("%s", str[0] + 1);
		scanf("%s", str[1] + 1);
		int m = (int)strlen(str[0] + 1);
		
		int pre = 0, suf = 0;
		while (pre + 1 <= m && str[0][pre + 1] == str[1][pre + 1]) pre++;
		while (suf + 1 <= m && str[0][m - suf] == str[1][m - suf]) suf++; 
		
		long long ans = 0; 
		
		int p = 0;
		for (int j = 1; j <= 2 * m; j++)
		{
			char c = j % 2 == 1 ? str[0][j / 2 + 1] : str[1][j / 2];
			p = next[p][c - 'a'];
			
			if (j % 2 == 0 && j >= 2 * m - 2 * suf)
			{
				if (len[p] >= j - 2 * pre)
				{
					ans += cnt[p];
					ans -= cnt[find(p, j - 2 * pre - 1)];
				}

//				printf("%d %d\n", p, find(p, j - 2 * pre - 1));
//				int t = p;
//				while (t != 0)
//				{
//					if (len[t] >= j - 2 * pre)
//					{
//						ans += cnt[t] - cnt[fail[t]];
//						printf("%d   ", t);
//					}
//					else printf("  %d", t);
//					t = fail[t];
//				}
//				printf("\n");
			}
			
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}



}

int main()
{
	wxr::main();
	return 0;
}

