#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

struct Trans {
	string u, v;
};

int n, q;
Trans tr[1003];

map<string, bool> vis;

int ans;

vector<int> Find(string st, string s) {
	vector<int> answ;
	for (int i = 0; i < st.size() - s.size() + 1; i++) {
		bool flg = 1;
		for (int j = 0, _i = i; j < s.size(); j++, _i++) {
			if (st[_i] != s[j]) {
				flg = 0;
				break;
			}
			if (j == s.size() - 1) {
				break;
			}
		}
		if (flg) {
			answ.push_back(i);
		}
	}
	return answ;
}

string target;
bool Dfs(string st, int cnt) {
	if (cnt >= 2) return 0;
	if (st == target) {
		ans++;
		return 1;
	}
	/*if (vis[st]) {
		ans++;
		return 1;
	}*/
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> r = Find(st, tr[i].u);
		for (int p : r) {
			string _st = st;
			for (int j = p, _j = 0; _j < tr[i].u.size(); _j++, j++) {
				_st[j] = tr[i].v[_j];
			}
			if (Dfs(_st, cnt + 1)) {
				vis[st] = 1;
				flg = 1;
			}
		}
	}
	return flg;
}

int main() {
	ios::sync_with_stdio(), cin.tie(0), cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> tr[i].u >> tr[i].v;
	}
	for (int i = 1; i <= q; i++) {
		string s, t;
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << "0\n";
		}
		target = t, ans = 0;
		Dfs(s, 0);
		cout << ans << '\n';
	}
	return 0;
}
