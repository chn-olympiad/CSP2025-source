#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, N = 5e6 + 5, bs = 131;
int n, m, dfn[N], cnt, sz[N], ed[2][maxn];
unordered_map<unsigned long long, int> mp[2];
struct Trie {
	int son[N][26], tot = 1;
	int ins(string &s) {
		int p = 1;
		for (int i = 0; i < s.size(); i++) {
			int id = s[i] - 'a';
			if(!son[p][id])
				son[p][id] = ++tot;
			p = son[p][id];
		}
		return p;
	}
	void dfs(int u, unsigned long long nw, int k) {
		dfn[u] = ++cnt; sz[u] = 1;
		mp[k][nw] = u;
	//	if(k == 1)
	//		cout << u << "asdf" << " " << cnt << endl;
		for (int i = 0; i < 26; i++) {
			if(son[u][i])
				dfs(son[u][i], (nw * bs + i + 1), k),
				sz[u] += sz[son[u][i]];
		}
	}
} Tree[2];
struct Qry {
	int id, pos, val;
};
long long ans[maxn];
vector<Qry> qry[N];
vector<int> opt[N];
unsigned long long h[2][N], pw[N];
void Prepare(string &s, string &t) {
	for (int i = 1; i <= s.size(); i++)
		h[0][i] = (h[0][i - 1] * bs + s[i - 1] - 'a' + 1);
	for (int i = 1; i <= t.size(); i++)
		h[1][i] = (h[1][i - 1] * bs + t[i - 1] - 'a' + 1);
}
unsigned long long my_query(int k, int l, int r) {
	if(l > r)
		return 0;
	l++, r++;
	return (h[k][r] - h[k][l - 1] * pw[r - l + 1]);
}
struct Tree_array {
	int tr[N];
	inline int lowbit(int x) {
		return (x & (-x));
	}	
	void add(int x, int val) {
		while(x <= cnt)
			tr[x] += val, x += lowbit(x);
	}
	int query(int x) {
		int ans = 0;
		while(x)
			ans += tr[x], x -= lowbit(x);
		return ans;
	}
	void addseg(int l, int r, int v) {
		if(r > cnt)
			cout << l << " " << r << " " << cnt << endl;
		add(l, v), add(r + 1, -v);
	}
} my_tree;
void solve(int u) {
	for (int i = 0; i < opt[u].size(); i++)
		my_tree.addseg(dfn[opt[u][i]], dfn[opt[u][i]] + sz[opt[u][i]] - 1, 1);
	for (int i = 0; i < qry[u].size(); i++) 
		ans[qry[u][i].id] += my_tree.query(dfn[qry[u][i].pos]) * qry[u][i].val; 
	for (int i = 0; i < 26; i++)
		if(Tree[0].son[u][i])
			solve(Tree[0].son[u][i]);
	for (int i = 0; i < opt[u].size(); i++)
		my_tree.addseg(dfn[opt[u][i]], dfn[opt[u][i]] + sz[opt[u][i]] - 1, -1);
}
int edt;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s, t; cin >> s >> t;
		ed[0][i] = Tree[0].ins(s), ed[1][i] = Tree[1].ins(t);
	}
	Tree[0].dfs(1, 0, 0);
	cnt = 0;
	Tree[1].dfs(1, 0, 1);
	for (int i = 1; i <= n; i++) 
		opt[ed[0][i]].push_back(ed[1][i]);
	pw[0] = 1;
	for (int i = 1; i <= 5000000; i++)
		pw[i] = pw[i - 1] * bs;
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		string s, t; cin >> s >> t;
		if(s.size() != t.size()) 
			continue;
		int l = 0, r = n + 1;
		for (int j = 0; j < s.size(); j++)
			if(s[j] != t[j]) {
				l = j - 1;
				break;
			}
		for (int j = s.size() - 1; j >= 0; j--) 
			if(s[j] != t[j]) {
				r = j + 1;
				break;
			}
		Prepare(s, t);
		for (int j = 0; j < s.size(); j++) {
			if(j > l + 1)
				continue;
			unsigned long long r0 = my_query(0, j, r - 1), r1 = my_query(1, j, r - 1);
	//		cout << r0 << " " << r1 << endl;
			if(!mp[0][r0] || !mp[1][r1])
				continue;
			int lx = max(j, r - 1), rx = s.size();
			while(lx + 1 < rx) {
				int mid = lx + rx >> 1;
				if(mp[0][my_query(0, j, mid)] && mp[1][my_query(1, j, mid)])
					lx = mid;
				else
					rx = mid;
			}
			r0 = lx;
	//		if(i == 245)
	//			cout << j << " " <<  lx << " " << l << " " << r - 2 << " " << mp[1][my_query(1, j, lx)] << endl;
	//		cout << mp[0][my_query(0, j, r - 2)] << endl;
			qry[mp[0][my_query(0, j, lx)]].push_back(Qry{i, mp[1][my_query(1, j, lx)], 1});
//			qry[mp[0][my_query(0, j, r - 2)]].push_back(Qry{i, mp[1][my_query(1, j, lx)], -1});
//			qry[mp[0][my_query(0, j, lx)]].push_back(Qry{i, mp[1][my_query(1, j, r - 2)], -1});
			qry[mp[0][my_query(0, j, r - 2)]].push_back(Qry{i, mp[1][my_query(1, j, r - 2)], -1});
	//		cout << j << endl;
			cnt += 2;
		}
	//	cout << cnt << endl;
	}
	solve(1);
	for (int i = 1; i <= m; i++)
		cout << ans[i] << endl;
	return 0;
} 
