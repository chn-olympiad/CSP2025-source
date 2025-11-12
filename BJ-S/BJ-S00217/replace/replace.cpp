#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (int)2e5 + 5;
const int M = (int)2.5e6 + 2e5 + 5;

int T, n, q, tot1, tot2, rt1[M], rt2[M], mp[N], qp[N], t1[M][26], t2[M][26];
vector<int> id[M], qry[M];
int nd, dfn[M], out[M], c[M], ans[N];

void dfs2(int u) {
	dfn[u] = ++nd;
	for (int j = 0; j < 26; j++) {
		if (t2[u][j]) {
			dfs2(t2[u][j]);
		}
	}
	out[u] = nd;
}

void add(int x, int v) {
	for (; x <= nd; x += x & -x) {
		c[x] += v;
	}
}

int query(int x) {
	int res = 0;
	for (; x; x -= x & -x) {
		res += c[x];
	}
	return res;
}

void dfs1(int u) {
	for (int i : id[u]) {
		int v = mp[i];
		add(dfn[v], 1);
		if (out[v] < nd) {
			add(out[v] + 1, -1);
		}
	}
	for (int i : qry[u]) {
		int v = qp[i];
		ans[i] = query(dfn[v]);
	}
	for (int j = 0; j < 26; j++) {
		if (t1[u][j]) {
			dfs1(t1[u][j]);
		}
	}
	for (int i : id[u]) {
		int v = mp[i];
		add(dfn[v], -1);
		if (out[v] < nd) {
			add(out[v] + 1, 1);
		}
	}
}

void work(int cid) {
	cin >> n >> q;
	tot1 = tot2 = 0;
	for (int i = 1; i <= n; i++) {
		string sa, sb;
		cin >> sa >> sb;
		if (sa == sb) {
			continue;
		}
		int l = 0, r = sa.size() - 1;
		while (sa[l] == sb[l]) {
			l++;
		}
		while (sa[r] == sb[r]) {
			r--;
		}
		int nl = r - l + 1;
		if (!rt1[nl]) {
			rt1[nl] = ++tot1;
		}
		int p = rt1[nl];
		for (int j = r; j >= 0; j--) {
			int c = sa[j] - 'a';
			if (!t1[p][c]) {
				t1[p][c] = ++tot1;
			}
			p = t1[p][c];
		}
		id[p].emplace_back(i);
		if (!rt2[nl]) {
			rt2[nl] = ++tot2;
		}
		p = rt2[nl];
		for (int j = l; j < sa.size(); j++) {
			int c = sb[j] - 'a';
			if (!t2[p][c]) {
				t2[p][c] = ++tot2;
			}
			p = t2[p][c];
		}
		mp[i] = p;
	}
	for (int i = 1; i <= q; i++) {
		string ta, tb;
		cin >> ta >> tb;
		if (ta.size() != tb.size()) {
			ans[i] = 0;
			continue;
		}
		int l = 0, r = ta.size() - 1;
		while (ta[l] == tb[l]) {
			l++;
		}
		while (ta[r] == tb[r]) {
			r--;
		}
		int nl = r - l + 1;
		if (!rt1[nl]) {
			ans[i] = 0;
			continue;
		}
		int p = rt1[nl];
		for (int j = r; j >= 0; j--) {
			int c = ta[j] - 'a';
			if (!t1[p][c]) {
				break;
			}
			p = t1[p][c];
		}
		qry[p].emplace_back(i);
		p = rt2[nl];
		for (int j = l; j < ta.size(); j++) {
			int c = tb[j] - 'a';
			if (!t2[p][c]) {
				break;
			}
			p = t2[p][c];
		}
		qp[i] = p;
	}
	for (int i = 1; i <= (int)2.5e6; i++) {
		if (rt1[i]) {
			dfs2(rt2[i]);
			dfs1(rt1[i]);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	T = 1;
	for (int cid = 1; cid <= T; cid++) {
		work(cid);
	}

	return 0;
}