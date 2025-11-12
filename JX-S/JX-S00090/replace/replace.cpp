#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define sr cin
#define sw cout
#define sendl '\n'
#define seia cout.flush();return 0

set<pair<string, string>> sfg;
int trie[2][5000010][26], fail[2][5000010], cnt[2] = {1, 1};
vector<int> f[2][5000010];
bool vis[200010];

void insert(int g, string str, int id) {
	int u = 1;
	for (char i : str) {
		if (trie[g][u][i - 'a'] == 0) {
			trie[g][u][i - 'a'] = ++cnt[g];
		}
		u = trie[g][u][i - 'a'];
	}
	f[g][u].push_back(id);
}

void init(int g, int u, int fa) {
	// sw << g << " " << u << sendl;
	if (fa == 0) {
		fail[g][u] = u;
	}
	for (int i = 0; i < 26; i++) {
		if (trie[g][u][i]) {
			if (u == 1) {
				fail[g][trie[g][u][i]] = 1;
				init(g, trie[g][u][i], u);
				continue;
			}
			int x = u;
			while (x != 1) {
				if (trie[g][fail[g][x]][i]) {
					fail[g][trie[g][u][i]] = trie[g][fail[g][x]][i];
					break;
				}
				x = fail[g][x];
			}
			if (x == 1) {
				fail[g][trie[g][u][i]] = 1;
			}
			// sw << g << " " << trie[g][u][i] << " " << u << " " << fail[g][trie[g][u][i]] << endl;
			init(g, trie[g][u][i], u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	sr >> n >> q;
	if (n > 100) {
		for (int i = 1; i <= n; i++) {
			string a, b;
			sr >> a >> b;
			insert(0, a, i);
			insert(1, b, i);
		}
			// cerr << "xxx" << endl;
		init(0, 1, 0);
		init(1, 1, 0);
			// cerr << "xxx" << endl;
		while (q--) {
			string t1, t2;
			sr >> t1 >> t2;
			int t = t1.size() - 1;
			while (t1[t] == t2[t]) {
				t--;
			}
			int u = 1, v = 1;
			for (int i = 0; i < t; i++) {
				if (trie[0][u][t1[i] - 'a']) {
					u = trie[0][u][t1[i] - 'a'];
				} else {
					int pre = u;
					int temp = u;
					while (temp != 1) {
						if (trie[0][fail[0][temp]][t1[i] - 'a']) {
							u = trie[0][fail[0][temp]][t1[i] - 'a'];
							break;
						}
						temp = fail[0][temp];
					}
					if (temp == 1) {
						u = 1;
					}
					trie[0][pre][t1[i] - '0'] = u;
				}
				if (trie[1][v][t2[i] - 'a']) {
					v = trie[1][v][t2[i] - 'a'];
				} else {
					int pre = v;
					int temp = v;
					while (temp != 1) {
						if (trie[1][fail[1][temp]][t2[i] - 'a']) {
							v = trie[1][fail[1][temp]][t2[i] - 'a'];
							break;
						}
						temp = fail[1][temp];
					}
					if (temp == 1) {
						v = 1;
					}
					trie[1][pre][t2[i] - '0'] = v;
				}
				unordered_set<int> s;
				int temp = u;
				do {
					for (int j : f[0][temp]) {
						s.insert(j);
					}
					temp = fail[0][temp];
				} while(temp != 1);
				temp = v;
				do {
					for (int j : f[1][temp]) {
						if (s.count(j)) {
							vis[j] = true;
						}
					}
					temp = fail[1][temp];
				} while(temp != 1);
			}
			// cerr << "xxx" << endl;
			i64 ans = 0;
			for (int i = t; i < t1.size(); i++) {
				if (trie[0][u][t1[i] - 'a']) {
					u = trie[0][u][t1[i] - 'a'];
				} else {
					int pre = u;
					int temp = u;
					while (temp != 1) {
						if (trie[0][fail[0][temp]][t1[i] - 'a']) {
							u = trie[0][fail[0][temp]][t1[i] - 'a'];
							break;
						}
						temp = fail[0][temp];
					}
					if (temp == 1) {
						u = 1;
					}
					trie[0][pre][t1[i] - '0'] = u;
				}
				if (trie[1][v][t2[i] - 'a']) {
					v = trie[1][v][t2[i] - 'a'];
				} else {
					int pre = v;
					int temp = v;
					while (temp != 1) {
						if (trie[1][fail[1][temp]][t2[i] - 'a']) {
							v = trie[1][fail[1][temp]][t2[i] - 'a'];
							break;
						}
						temp = fail[1][temp];
					}
					if (temp == 1) {
						v = 1;
					}
					trie[1][pre][t2[i] - '0'] = v;
				}
				unordered_set<int> s;
				int temp = u;
				do {
					for (int j : f[0][temp]) {
						s.insert(j);
					}
					temp = fail[0][temp];
				} while(temp != 1);
				int res = 0;
				temp = v;
				do {
					for (int j : f[1][temp]) {
						if (!vis[j]) {
							res += s.count(j);
							vis[j] = true;
						}
					}
					temp = fail[1][temp];
				} while(temp != 1);
				ans += res;
			}
			sw << ans << sendl;
		}
	} else {
		for (int i = 1; i <= n; i++) {
			string a, b;
			sr >> a >> b;
			sfg.insert({a, b});
		}
		while (q--) {
			string a, b;
			sr >> a >> b;
			int l = 0;
			while (a[l] == b[l]) {
				l++;
			}
			int r = a.size() - 1;
			while (a[r] == b[r]) {
				r--;
			}
			int res = 0;
			for (int i = 0; i <= l; i++) {
				string t1 = a.substr(i, r - 1 - i + 1);
				string t2 = b.substr(i, r - 1 - i + 1);
				for (int j = r; j < a.size(); j++) {
					t1.push_back(a[j]);
					t2.push_back(b[j]);
					if (sfg.count({t1, t2})) {
						res++;
					}
				}
			}
			sw << res << sendl;
		}
	}
	seia;
}