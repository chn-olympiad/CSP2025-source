#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

const int mod1 = 1e9 + 3;
const int base1 = 1221;
const int mod2 = 1e9 + 7;
const int base2 = 121;
struct node {
	int x, y;
	node() {x = y = 0;}
};
node operator+ (node x, int c) {
	x.x = (1ll * x.x * base1 % mod1 + c) % mod1;
	x.y = (1ll * x.y * base2 % mod2 + c) % mod2;
	return x;
}
bool operator< (node x, node y) {
	if (x.x == y.x) return x.y < y.y;
	else return x.x < y.x;
}

const int N = 2e5 + 10;
const int M = 5e6 + 10;
int n, q, pre[N], suf[N], qpre[N], qsuf[N];
int ans[N];
std::string s[N], t[N], qs[N], qt[N];
std::vector < int > vec[N], que[N];
std::map < std::pair < node, node > , int > id;

int dfntot, tot;
int dfn[M], size[M], belong[N], qbelong[N];
int son[M][26];
std::vector < int > hav[M], qhav[M], eg[M];

namespace BIT {
	#define lowbit(x) (x & (-x))
	int sum[M];
	void add (int x, int k) {
		for (int i = x; i <= dfntot; i += lowbit(i))
			sum[i] += k;
	}
	int getsum (int x) {
		int ans = 0;
		for (int i = x; i; i -= lowbit(i))
			ans += sum[i];
		return ans;
	}
	void modify (int l, int r, int k) {
		add(l, k), add(r + 1, -k);
	}
}

void dfs1 (int x) {
	dfn[x] = ++dfntot;
	size[x] = 1;
	for (int to : eg[x]) {
		dfs1(to);
		size[x] = size[x] + size[to];
	}
}

void dfs2 (int x) {
	for (int cur : hav[x]) 
		BIT::modify(dfn[belong[cur]], dfn[belong[cur]] + size[belong[cur]] - 1, 1);
	for (int cur : qhav[x])
		ans[cur] = BIT::getsum(dfn[qbelong[cur]]);
	for (int to : eg[x]) dfs2(to);
	for (int cur : hav[x]) 
		BIT::modify(dfn[belong[cur]], dfn[belong[cur]] + size[belong[cur]] - 1, -1);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i] >> t[i];
		pre[i] = -1, suf[i] = s[i].size();
		while (pre[i] + 1 < int(s[i].size()) && s[i][pre[i] + 1] == t[i][pre[i] + 1]) pre[i]++;
		while (suf[i] - 1 >= 0 && s[i][suf[i] - 1] == t[i][suf[i] - 1]) suf[i]--;
		if (pre[i] >= suf[i]) continue;
		node val1, val2;
		for (int j = pre[i] + 1; j < suf[i]; j++) {
			val1 = val1 + int(s[i][j] - 'a' + 1);
			val2 = val2 + int(t[i][j] - 'a' + 1);
		}
		std::pair < node, node > tmp = {val1, val2};
		int cur;
		if (!id[tmp]) cur = id[tmp] = id.size();
		else cur = id[tmp];
		vec[cur].push_back(i);
	}
	for (int i = 1; i <= q; i++) {
		std::cin >> qs[i] >> qt[i];
		qpre[i] = -1, qsuf[i] = qs[i].size();
		
		while (qpre[i] + 1 < int(qs[i].size()) && qs[i][qpre[i] + 1] == qt[i][qpre[i] + 1]) qpre[i]++;
		while (qsuf[i] - 1 >= 0 && qs[i][qsuf[i] - 1] == qt[i][qsuf[i] - 1]) qsuf[i]--;
		node val1, val2;
		for (int j = qpre[i] + 1; j < qsuf[i]; j++) {
			val1 = val1 + int(qs[i][j] - 'a' + 1);
			val2 = val2 + int(qt[i][j] - 'a' + 1);
		}
		std::pair < node, node > tmp = {val1, val2};
		if (id.count(tmp)) que[id[tmp]].push_back(i);
	}
	int all = id.size();
	for (int i = 1; i <= all; i++) {
		int root1 = 1, root2 = 2;
		tot = 2;
		for (int x : vec[i]) {
			int pos = root1;
			for (int j = pre[x]; ~j; j--) {
				if (!son[pos][s[x][j] - 'a']) {
					son[pos][s[x][j] - 'a'] = ++tot;
					eg[pos].push_back(tot);
				}
				pos = son[pos][s[x][j] - 'a'];
			}
			hav[pos].push_back(x);
			pos = root2;
			for (int j = suf[x]; j < int(s[x].size()); j++) {
				if (!son[pos][s[x][j] - 'a']) {
					son[pos][s[x][j] - 'a'] = ++tot;
					eg[pos].push_back(tot);
				}
				pos = son[pos][s[x][j] - 'a'];
			}
			belong[x] = pos;
		}
		for (int x : que[i]) {
			int pos = root1;
			for (int j = qpre[x]; ~j; j--) {
				if (!son[pos][qs[x][j] - 'a']) {
					son[pos][qs[x][j] - 'a'] = ++tot;
					eg[pos].push_back(tot);
				}
				pos = son[pos][qs[x][j] - 'a'];
			}
			qhav[pos].push_back(x);
			pos = root2;
			for (int j = qsuf[x]; j < int(qs[x].size()); j++) {
				if (!son[pos][qs[x][j] - 'a']) {
					son[pos][qs[x][j] - 'a'] = ++tot;
					eg[pos].push_back(tot);
				}
				pos = son[pos][qs[x][j] - 'a'];
			}
			qbelong[x] = pos;
		}
		dfntot = 0;
		dfs1(root2);
		dfs2(root1);
		for (int j = 1; j <= tot; j++) {
			hav[j].clear(), qhav[j].clear(); eg[j].clear();
			for (int ch = 0; ch < 26; ch++) son[j][ch] = 0;
		}
	}
	for (int i = 1; i <= q; i++)
		std::cout << ans[i] << '\n';
	return 0;
}
