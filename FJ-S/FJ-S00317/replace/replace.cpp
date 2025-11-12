#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, Q, L[N], R[N];
string x[N], y[N];
map<string, vector<int>> mp;
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i], x[i] = " " + x[i], y[i] = " " + y[i];
		int len = x[i].size();
		for (int j = 1; j <= len; j++)
			if (x[i][j] != y[i][j]) {
				L[i] = j;
				break;
			} 
		for (int j = len; j >= 1; j--)
			if (x[i][j] != y[i][j]) {
				R[i] = j;
				break;
			}
		string str = ""; 
		for (int j = L[i]; j <= R[i]; j++) str += x[i][j];
		str += " ";
		for (int j = L[i]; j <= R[i]; j++) str += y[i][j];
		mp[str].push_back(i);
	}
	while (Q--) {
		string s, t; cin >> s >> t;
		if (s.size() != t.size()) {
			cout << "0\n";
			continue;
		}
		int len = s.size();
		s = " " + s, t = " " + t;
		int l = 0, r = 0; 
		for (int i = 1; i <= len; i++)
			if (s[i] != t[i]) {
				l = i;
				break;
			}
		for (int i = len; i >= 1; i--)
			if (s[i] != t[i]) {
				r = i;
				break;
			}
		string a = "", b = "";
		for (int i = l; i <= r; i++) a += s[i], b += t[i];
		if (mp.count((string)(a + " " + b))) {
			int cnt = 0;
			for (auto P : mp[(string)(a + " " + b)]) {
				if (l < L[P] || len - r < (int)x[P].size() - R[P] - 1) continue;
				int i = L[P] - 1, j = l - 1;
				bool flag = 1;
				while (i) {
					if (x[P][i] != s[j]) {
						flag = 0;
						break;
					}
					i--, j--;
				}
				if (!flag) continue;
				i = R[P] + 1, j = r + 1;
				while (i < (int)x[P].size()) {
					if (x[P][i] != s[j]) {
						flag = 0;
						break;
					}
					i++, j++;
				}
				if (flag) cnt++;
			}
			cout << cnt << "\n";
		} else cout << "0\n"; 
	} 
	return 0;
}

