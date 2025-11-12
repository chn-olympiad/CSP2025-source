#include <bits/stdc++.h>
#include <string>
using namespace std;
map<string, string> s;
int nfs(string t1, string t2) {
	int ans = 0;
	for (int i = 0; i < t1.size(); ++i) {
		for (auto p : s) {
			if (t1.size() - i <= p.first.size() && i < t1.size()) {
				if (t1.substr(i, p.first.size()) == p.first) {
					string ns = t1.substr(0, i) + p.second + t1.substr(i + p.first.size(), t1.size() - p.first.size() - i);
					if (ns == t2) {
						++ans;
					}
				}
			}
		}
	}
	return ans;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		s[s1] = s2;
	}
	for (int i = 1; i <= q; ++i) {
		string t1, t2;
		cin >> t1 >> t2;
		cout << nfs(t1, t2) << "\n";
	}
}
