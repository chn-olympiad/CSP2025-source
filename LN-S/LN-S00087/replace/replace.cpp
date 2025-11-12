#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 5;
int n, q;
string s[maxn][3];

int find(string s1, string s2, int time) {
	int cnt = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == s2[0]) {
			bool flag = true;
			for (int j = 1; j < s2.length(); j++) {
				if (s1[i + j] != s2[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
				if (cnt == time) {
					return i;
				}
			}
		}
	}
	if (!cnt) {
		return -1;
	}
}

string replace(string s1, string s2, int id) {
	for (int i = id; i <= id + s2.length() - 1; i++) {
		s1[i] = s2[i - id];
	}
	return s1;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; ; k++) {
				int res = find(t1, s[j][1], k);
				if (res != -1) {
					if (replace(t1, s[j][2], res) == t2) {
						cnt++;
					}
				}
				else break;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
