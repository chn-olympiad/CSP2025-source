#include <bits/stdc++.h>
using namespace std;

const int N = 200000, V = 2500000;

int n, q;
string s[N + 10][2], t[N + 10][2];
int s_len[N + 10], t_len[N + 10];
int l[N + 10], r[N + 10];

int rt = 0, tot = 0;
map<int, int> tr[V + 10];
int fail[V + 10], val[V + 10], cnt[V + 10], ind[V + 10];
vector<int> dep[V + 10], sum[V + 10];

int pos[V + 10];
queue<int> que;

int getid(char u, char v) {
	return ((int)u - (int)'a') * 27 + ((int)v - (int)'a'); 
}

void insert(string s1, string s2, int len) {
	int p = rt;
	for(int i = 0; i < len; ++i) {
		int id = getid(s1[i], s2[i]);
		if(!tr[p].count(id)) tr[p][id] = ++tot;
		p = tr[p][id];
	}
	val[p] = len; ++cnt[p];
}

void build() {
	for(pair<int, int> ne_dot : tr[0]) que.push(ne_dot.second);
	while(!que.empty()) {
		int u = que.front(); que.pop();
		for(pair<int, int> ne_dot : tr[u]) {
			int id = ne_dot.first, v = ne_dot.second, x = fail[u];
			while(x && !tr[x].count(id)) x = fail[x];
			if(tr[x].count(id)) x = tr[x][id];
			fail[v] = x; que.push(v);
		}
	}
}

int get_ne(int req, int p) {
	while(p && !tr[p].count(req)) p = fail[p];
	if(tr[p].count(req)) p = tr[p][req];
	return p;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i][0] >> s[i][1];
		s_len[i] = (int)s[i][0].length();
		int flag = 1;
		for(int j = 0; j < s_len[i]; ++j) {
			if(s[i][0][j] != s[i][1][j]) {
				flag = 0; break;
			}
		}
		if(!flag) insert(s[i][0], s[i][1], s_len[i]);
	}
	build();
	for(int i = 1; i <= q; ++i) {
		cin >> t[i][0] >> t[i][1];
		t_len[i] = (int)t[i][1].length();
	}
	for(int i = 1; i <= q; ++i) {
		if(t[i][0].length() != t[i][1].length()) continue;
		l[i] = V + 1, r[i] = 0;
		for(int j = 0; j < t_len[i]; ++j) {
			if(t[i][0][j] != t[i][1][j]) {
				l[i] = min(l[i], j + 1); r[i] = max(r[i], j + 1);
			}
		}
	}
	q = 1;
	for(int i = 1; i <= q; ++i) {
		if(t[i][0].length() != t[i][1].length()) {
			cout << 0 << '\n'; continue;
		}
		int p = rt, ans = 0;
		for(int j = 1; j <= tot; ++j) pos[j] = 0;
		for(int j = 2; j <= tot; ++j) ++ind[fail[j]];
		for(int j = 1; j <= t_len[i]; ++j) {
			p = get_ne(getid(t[i][0][j - 1], t[i][1][j - 1]), p);
//			cout << p << ' ';
			if(j >= r[i]) pos[p] = j;
		}
//		cout << '\n';
		for(int j = 1; j <= tot; ++j) {
			if(!ind[j]) que.push(j);
		}
		while(!que.empty()) {
			int u = que.front(); que.pop();
//			cout << u << ' ' << pos[u] << '\n';
			if(cnt[u] && pos[u]) {
				if(pos[u] - val[u] < l[i]) ans += cnt[u];
			}
			if(u == 1) continue;
			if(!pos[fail[u]]) pos[fail[u]] = pos[u];
			--ind[fail[u]];
			if(!ind[fail[u]]) que.push(fail[u]);
		}
		cout << ans << '\n';
	}
	return 0;
}
