#include <bits/stdc++.h>
using namespace std;
const long long base = 13331, mod = (1ll << 61) - 1;
struct node {
	int x, y, id;
}a[200005];
vector<node> v[5000005], q[500005];
map<pair<long long, long long>, vector<int>> mp, mp2;
string s[200005], t[200005], qs[200005], qt[200005];
int n, m, k, l[200005], r[200005], ql[200005], qr[200005], ans[200005];
struct Trie {
	int cnt, tot, id[5000005], l[5000005], r[5000005], to[5000005][26];
	int insert(string s) {
		int x = 0;
		for(auto i : s) {
			if(!to[x][i - 'a'])
				to[x][i - 'a'] = ++cnt;
			x = to[x][i - 'a'];
		}
		return x;
	}
	void dfs(int x) {
		l[x] = ++tot;
		for(int i = 0; i < 26; i++)
			if(to[x][i])
				dfs(to[x][i]);
		r[x] = tot;
		return;
	}
	int find(string s) {
		int x = 0;
		for(auto i : s) {
			if(!to[x][i - 'a'])
				break;
			x = to[x][i - 'a'];
		}
		return l[x];
	}
	void clear() {
		for(int i = 0; i <= cnt; i++)
			memset(to[i], l[i] = 0, sizeof(to[i]));
		cnt = tot = 0;
		return;
	}
}T1, T2;
struct BIT {
	int t[5000005];
	int lowbit(int x) {
		return x & -x;
	}
	void update(int x, int v) {
		while(x <= T2.tot)
			t[x] += v, x += lowbit(x);
		return;
	}
	int query(int x) {
		int s = 0;
		while(x)
			s += t[x], x -= lowbit(x);
		return s;
	}
	void update(int l, int r, int v) {
		return update(l, v), update(r + 1, -v);
	}
	void clear() {
		for(int i = 0; i <= T2.tot; i++)
			t[i] = 0;
		return;
	}
}T;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
		for(l[i] = 0; l[i] < s[i].size() && s[i][l[i]] == t[i][l[i]]; l[i]++);
		for(r[i] = s[i].size() - 1; ~r[i] && s[i][r[i]] == t[i][r[i]]; r[i]--);
		long long h = 0, h2 = 0;
		for(int j = l[i]; j <= r[i]; j++)
			h = ((__int128)h * base + s[i][j]) % mod, h2 = ((__int128)h2 * base + t[i][j]) % mod;
		mp[{h, h2}].push_back(i);
	}
	for(int i = 1; i <= m; i++) {
		cin >> qs[i] >> qt[i];
		if(qs[i].size() != qt[i].size())
			continue;
		for(ql[i] = 0; ql[i] < qs[i].size() && qs[i][ql[i]] == qt[i][ql[i]]; ql[i]++);
		for(qr[i] = qs[i].size() - 1; ~qr[i] && qs[i][qr[i]] == qt[i][qr[i]]; qr[i]--);
		long long h = 0, h2 = 0;
		for(int j = ql[i]; j <= qr[i]; j++)
			h = ((__int128)h * base + qs[i][j]) % mod, h2 = ((__int128)h2 * base + qt[i][j]) % mod;
		mp2[{h, h2}].push_back(i);
	}
	for(auto p : mp) {
		T1.clear(), T2.clear(), k = 0;
		auto tmp = mp2[p.first];
		if(!tmp.size())
			continue;
		for(int i : p.second) {
			auto b = s[i].substr(0, l[i]);
			reverse(b.begin(), b.end()), a[++k] = {T1.insert(b), T2.insert(s[i].substr(r[i] + 1))};
		}
		T1.dfs(0), T2.dfs(0);
		for(int i : tmp) {
			auto p = qs[i].substr(0, ql[i]);
			reverse(p.begin(), p.end()), q[T1.find(p)].push_back({T2.find(qs[i].substr(qr[i] + 1)), 0, i});
		}
		for(int i = 1; i <= k; i++)
			v[T1.l[a[i].x]].push_back({T2.l[a[i].y], T2.r[a[i].y], 1}), v[T1.r[a[i].x] + 1].push_back({T2.l[a[i].y], T2.r[a[i].y], -1});
		for(int i = 0; i <= T1.tot + 1; i++) {
			for(auto j : v[i])
				T.update(j.x, j.y, j.id);
			for(auto j : q[i])
				ans[j.id] = T.query(j.x);
			v[i].clear(), q[i].clear();
		}
		T.clear();
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
	return 0;
}