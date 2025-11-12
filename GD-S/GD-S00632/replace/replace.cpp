#include <bits/stdc++.h>
#define fi first
#define se second
#define il inline 
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5, S = 27, mod1 = 1e9 + 9, mod2 = 998244353, bas1 = 29, bas2 = 37;
struct hs {
	int val1, val2;
	il hs(int v1 = 0, int v2 = 0) {val1 = v1, val2 = v2; }
	il hs operator + (int c) {
		int v1 = (val1 * bas1 + c) % mod1;
		int v2 = (val2 * bas2 + c) % mod2;
		return {v1, v2};
	}
	il bool operator < (hs v) const {
		if (val1 != v.val1) return val1 < v.val1;
		return val2 < v.val2;
	}
	il bool operator == (hs v) const {
		return val1 == v.val1 and val2 == v.val2;
	} 
};
int n, q, out[N];
string s[N][2], t[N][2];
vector<string> a[N];
vector<pair<string, int> > b[N];
map<pair<hs, hs>, int> id; int hid;
int tot, cnt[M], son[M][S], tr[M], deg[M]; 
vector<int> g[M];
il void clear() {
	for (int i = 0; i <= tot; i++) {
		cnt[i] = tr[i] = deg[i] = 0;
		g[i].clear();
		for (int j = 0; j < S; j++) {
			son[i][j] = 0;
		}
	}
	tot = 0;
}
il void insert(string s) {
	int len = s.size(), u = 0;
	for (int i = 0; i < len; i++) {
		int d = s[i] - 'a';
		if (!son[u][d]) son[u][d] = ++tot;
		u = son[u][d];
	}
	cnt[u]++;
}
il void build() {
	queue<int> q;
	for (int i = 0; i < S; i++) if (son[0][i]) {
		q.push(son[0][i]);
	}
	for (int u; !q.empty(); ) {
		u = q.front();
		q.pop();
		for (int c = 0; c < S; c++) {
			if (son[u][c]) {
				tr[son[u][c]] = son[tr[u]][c];
				if (tr[son[u][c]]) {
					deg[son[u][c]]++;
					g[tr[son[u][c]]].push_back(son[u][c]);
				}
				q.push(son[u][c]);
			} else {
				son[u][c] = son[tr[u]][c];
			}
		}
	}
}
il void topo() {
	queue<int> q;
	for (int i = 1; i <= tot; i++) if (!deg[i]) {
		q.push(i);
	}
	for (int u; !q.empty(); ) {
		u = q.front();
		q.pop();
		for (int v : g[u]) {
			deg[v]--;
			cnt[v] += cnt[u];
			if (!deg[v]) q.push(v);
		}
	}
}
il int query(string s) {
	int len = s.size(), u = 0, res = 0;
	for (int i = 0; i < len; i++) {
		int d = s[i] - 'a';
		u = son[u][d];
		res += cnt[u];
	} 
	return res;
}
il void solve(int x) {
	clear();
	for (string s : a[x]) insert(s);
	build();
	topo();
	for (pair<string, int> s : b[x]) out[s.se] = query(s.fi);
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
	}
	for (int i = 1; i <= n; i++) {
		if (s[i][0] == s[i][1]) continue;
		int l = -1, r = -1, len = s[i][0].size();
		for (int j = 0; j <= len - 1; j++) {
			if (s[i][0][j] != s[i][1][j]) {
				l = j; break;
			} 
		}
		for (int j = len - 1; j >= 0; j--) {
			if (s[i][0][j] != s[i][1][j]) {
				r = j; break;
			}
		}
		pair<hs, hs> h;
		string now;
		for (int j = 0; j < len; j++) {
			if (l <= j and j <= r) {
				h.fi = h.fi + (s[i][0][j] - 'a' + 1);
				h.se = h.se + (s[i][1][j] - 'a' + 1);
				if (j == l) now += char('z' + 1);
			} else {
				now += s[i][0][j];
			}
		}
		if (!id[h]) id[h] = ++hid;
		a[id[h]].push_back(now);
	} 
	for (int i = 1; i <= q; i++) {
		if (t[i][0].size() != t[i][1].size()) continue;
		int l = -1, r = -1, len = t[i][0].size();
		for (int j = 0; j <= len - 1; j++) {
			if (t[i][0][j] != t[i][1][j]) {
				l = j; break;
			} 
		}
		for (int j = len - 1; j >= 0; j--) {
			if (t[i][0][j] != t[i][1][j]) {
				r = j; break;
			}
		}
		pair<hs, hs> h;
		string now;
		for (int j = 0; j < len; j++) {
			if (l <= j and j <= r) {
				h.fi = h.fi + (t[i][0][j] - 'a' + 1);
				h.se = h.se + (t[i][1][j] - 'a' + 1);
				if (j == l) now += char('z' + 1);
			} else {
				now += t[i][0][j];
			}
		}
		if (!id[h]) continue;
		b[id[h]].push_back({now, i});
	} 
	for (int i = 1; i <= hid; i++) solve(i);
	for (int i = 1; i <= q; i++) cout << out[i] << '\n';
}
