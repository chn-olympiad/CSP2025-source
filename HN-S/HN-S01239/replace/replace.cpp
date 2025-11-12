#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
map<string, string> to;
bool flag;
int id[N][2];
bool check(string s) {
	bool flag1 = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'b') return 0;
		if (s[i] == 'b') {
			if (flag1 == 0) {
				flag1 = 1;
			} else {
				return 0;
			}
		}
	}
	return 1;
}
void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	if (!flag) {
		if (check(s1) && check(s2)) {
			int pos1b = 0, pos2b = 0;
			for (int i = 0; i < s1.size(); i++) {
				if (s1[i] != s2[i]) {
					if (s1[i] == 'b') pos1b = i;
					else pos2b = i;
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (pos1b - pos2b == id[i][1] - id[i][2] && pos1b >= id[i][1]) {
					ans++;
				}
			}
			cout << ans << "\n";
			return ; 
		}
	}
	if (s1.size() != s2.size()) {
		cout << "0\n";
		return ;
	}
	int l = s1.size();
	string x = "", y = "";
	int lt, rt;
	bool flag = 0;
	for (int i = 0; i < l; i++) {
		if (s1[i] != s2[i]) {
			if (flag) {
				cout << "0\n";
				return ;
			} else {
				lt = i;
				while (s1[i] != s2[i]) {
					x += s1[i];
					y += s2[i];
					i++;
				}
				rt = i - 1;
				continue;
			}
		}
	}
	// cout << y << " " << x << " " << lt << " " << rt << "\n";
	int ans = 0;
	if (to[x] == y) {
		ans++;
	}
	string lx = "", ly = "", rx = "", ry = "";
	for (int i = lt - 1; i >= 0; i--) {
		lx = s1[i] + lx, ly = s2[i] + ly;
		if (to[lx + x] == ly + y) {
			ans++;
		}
	}
	lx = "", ly = "";
	for (int i = lt - 1; i >= 0; i--) {
		lx = s1[i] + lx, ly = s2[i] + ly;
		rx = "", ry = "";
		for (int j = rt + 1; j < l; j++) {
			rx += s1[j], ry += s2[j];
			// cout << lx + x + rx << " " << ly + y + ry << "\n";
			if (to[lx + x + rx] == ly + y + ry) {
				ans++;
			}
		}
	}
	for (int i = rt + 1; i < l; i++) {
		x += s2[i], y += s2[i];
		if (to[x] == y) {
			ans++;
		}
	}
	cout << ans << "\n";
	return ;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	string s1, s2;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		if (check(s1) && check(s2)) {
			int pos1b = 0, pos2b = 0;
			for (int j = 0; j < s1.size(); j++) {
				if (s1[j] == 'b') {
					id[j][0] = j;
				}
			}	
			for (int j = 0; j < s2.size(); j++) {
				if (s2[j] == 'b') {
					id[j][1] = j;
				}
			}
		} else {
			flag = 1;
		}
		to[s1] = s2;
	}
	while (q--) {
		solve();
	}
	return 0;
}
/*
rp++
*/

