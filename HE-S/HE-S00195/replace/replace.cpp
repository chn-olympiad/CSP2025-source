#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q;
string s1[MAXN];
string s2[MAXN];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int o = 0; o < q; o++) {
		int cnt = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int t1l = t1.length();
		for (int i = 1; i <= n; i++) {
			int sl = s1[i].length();
			int l = 0, r = 0, cur = 0;
			bool ok = false;
			for (int j = 0; j < t1l; j++) {
				if (t1[j] == s1[i][cur]) {
					if (cur == 0) l = j;
					r = j;
					cur++;
					if (cur >= sl) {
						ok = true;
						break;
					}
				}
				else {
					cur = 0;
				}
			}
			if (ok) {
				string res;
				for (int j = 0; j < t1l; j++) {
					if (j == l) {
						res += s2[i];
						j = r;
					}
					else {
						res += t1[j];
					}
				}
				if (res == t2) {
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
	return 0;
}

