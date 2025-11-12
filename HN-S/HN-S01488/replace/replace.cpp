#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using node = array<int, 4>;
const int N = 2e5 + 10, M = 5e6 + 100;

int trie[M][26], sz[M], dfn[M], dcnt, tcnt = 1;

int nl[N], nr[N], nc[N][2], ql[N], qr[N], qc[N][2];
int ans[N];

int getId(const string &s, int tp = 0) {
	int u = 1;
	for(char c : s) {
		if(!trie[u][c - 'a']) {
			if(tp == 0) trie[u][c - 'a'] = ++tcnt;
			else if(tp == 1) return u;
			else return 0;
		}
		u = trie[u][c - 'a'];
	}
	return u;
}

void dfs(int u) {
	sz[u] = 1;
	dfn[u] = ++dcnt;
	for(int i = 0; i < 26; i ++) {
		if(!trie[u][i]) continue;
		dfs(trie[u][i]);
		sz[u] += sz[trie[u][i]];
	}
}

int tr[M];
bool vis[N];

void add(int p, int x) {
	while(p <= tcnt) {
		tr[p] += x;
		p += p & -p;
	}
}

int ask(int p) {
	int ret = 0;
	while(p > 0) {
		ret += tr[p];
		p -= p & -p;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("replace");
	
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i ++) {
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == s2) continue;
		int l = 0, r = s1.size() - 1;
		while(s1[l] == s2[l]) l ++;
		while(s1[r] == s2[r]) r --;
		reverse(s1.begin(), s1.begin() + l);
		nl[i] = getId(s1.substr(0, l));
		nr[i] = getId(s1.substr(r + 1, s1.size()));
		nc[i][0] = getId(s1.substr(l, r - l + 1));
		nc[i][1] = getId(s2.substr(l, r - l + 1));
	}
	
	for(int i = 1; i <= q; i ++) {
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.size() != s2.size()) continue;
			int l = 0, r = s1.size() - 1;
		while(s1[l] == s2[l]) l ++;
		while(s1[r] == s2[r]) r --;
		reverse(s1.begin(), s1.begin() + l);
		ql[i] = getId(s1.substr(0, l), 1);
		qr[i] = getId(s1.substr(r + 1, s1.size()), 1);
		qc[i][0] = getId(s1.substr(l, r - l + 1), 2);
		qc[i][1] = getId(s2.substr(l, r - l + 1), 2);
	}
	
	dfs(1);
	
	vector<node> v;
	for(int i = 1; i <= n; i ++) {
		if(!nc[i][0]) continue;
		v.push_back(node{nc[i][0], nc[i][1], dfn[nl[i]], i});
		v.push_back(node{nc[i][0], nc[i][1], dfn[nl[i]] + sz[nl[i]], i});
		// cout << i << ": " << nc[i][0] << " " << nc[i][1] << " (" << dfn[nl[i]] << ", " << dfn[nl[i]] + sz[nl[i]] << ")\n";
	}
	
	for(int i = 1; i <= q; i ++) {
		if(qc[i][0] && qc[i][1]) {
			v.push_back(node{qc[i][0], qc[i][1], dfn[ql[i]], n + i});
			// cout << i << " query: " << qc[i][0] << " " << qc[i][1] << " {" << dfn[ql[i]] << ", " << dfn[qr[i]] << "}\n";
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int _ = 0; _ < v.size(); _ ++) {
		int i = v[_][3];
		// cout << "*" << i << "\n";
		if(i <= n) {
			if(vis[i]) {
				add(dfn[nr[i]], -1);
				add(dfn[nr[i]] + sz[nr[i]], 1);
			}else{
				add(dfn[nr[i]], 1);
				add(dfn[nr[i]] + sz[nr[i]], -1);
				vis[i] = true;
			}
		}else{
			i -= n;
			ans[i] = ask(dfn[qr[i]]);
		}
	}
	for(int i = 1; i <= q; i ++)
		cout << ans[i] << "\n";
}
