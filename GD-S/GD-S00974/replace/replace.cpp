#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using f64 = double;
using f80 = long double;

#define FILE "replace"
#define endl "\n"

const i64 MOD = 998244353;
const i32 N = 1e6;

struct ACauto {
	i32 idx;
	i32 state[N];
	i32 childen[N][26];
	i32 fail[N];
	
	ACauto() : idx(0) {
		memset(state, 0, sizeof(state));
		memset(childen, 0, sizeof(childen));
		memset(fail, 0, sizeof(fail));
	}
	void insert(string str, i32 id) {
		i32 node = 0;
		for (char ch: str) {
			i32 digit = ch - 'a';
			if (!childen[node][digit]) childen[node][digit] = ++idx;
			node = childen[node][digit];
		}
		state[node] = id;
	}
	void build() {
		queue<i32> que;
		for (i32 i=0; i<26; ++i)
			if (childen[0][i]) que.push(childen[0][i]);
		while (!que.empty()) {
			i32 u = que.front(); que.pop();
			for (i32 i=0; i<26; ++i) {
				i32 &v = childen[u][i];
				if (v) {
					fail[v] = childen[fail[u]][i];
					que.push(v);
				} else v = childen[fail[u]][i];
			}
		}
	}
} ac1, ac2;

void solve() {
	i32 n, q; cin >> n >> q;
	for (i32 i=1; i<=n; ++i) {
		string s1, s2; cin >> s1 >> s2;
		ac1.insert(s1, i);
		ac2.insert(s2, i);
	}
	ac1.build();
	ac2.build();
	i32 ans = 0;
	while (q--) {
		string t1, t2; cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		i32 n1 = 0, n2 = 0;
		for (i32 i=0; i<t1.size(); ++i) {
			i32 d1 = t1[i] - 'a';
			i32 d2 = t2[i] - 'a';
			n1 = ac1.childen[n1][d1];
			n2 = ac2.childen[n2][d2];
			i32 u = n1, v = n2;
			while (u && v) {
				if (ac1.state[u] == ac2.state[v]) ++ans;
				u = ac1.fail[u];
				v = ac2.fail[v];
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen(FILE ".in", "r", stdin);
	freopen(FILE ".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
