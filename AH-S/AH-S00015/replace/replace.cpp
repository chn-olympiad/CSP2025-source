#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 2;
const int M = 1e2 + 2;
int n, q, cnt, jdg, idxs[N], idxt[N], lenn[N];
string s[N], t[N];
map<string, string> vis;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		int len = s[i].size();
		for (int j = 0; j < len; j++) {
			if (s[i][j] == 'b') {
				idxs[i] = j;
			}
			if (t[i][j] == 'b') {
				idxt[i] = j;
			}
		}
		lenn[i] = len;
		vis[s[i]] = t[i];
		jdg += (s[i].size() + t[i].size());
	}
	while (q--) {
		string ss, tt;
		cin >> ss >> tt;
		if (jdg <= 2000) {
			cnt = 0;
			int lens = ss.size(), lent = tt.size();
			if (lens != lent) {
				puts("0");
				continue;
			}
			for (int i = 0; i < lens; i++) {
				for (int j = i; j < lens; j++) {
					string r = ss.substr(i, j - i + 1);
					string ttt = "";
					if (vis[r].size()) {
						ttt = ss.substr(0, i) + vis[r] + ss.substr(j + 1);
						if (ttt == tt) {
							cnt++;
						}
					}
				}
			}
			printf("%d\n", cnt);
		} else {
			cnt = 0;
			int lens = ss.size(), lent = tt.size(), idxss, idxtt;
			if (lens != lent) {
				puts("0");
				continue;
			}
			for (int i = 0; i < lens; i++) {
				if (ss[i] == 'b') {
					idxss = i;
				}
			}
			for (int i = 0; i < lent; i++) {
				if (tt[i] == 'b') {
					idxtt = i;
				}
			}
			for (int i = 0; i < n; i++) {
				if (lenn[i] > lens || lenn[i] > lent || idxs[i] > idxss || (lenn[i] - 1 - idxs[i]) > (lens - 1 - idxss)) {
					continue;
				}
				int lcnt = idxss + idxt[i] - idxs[i], rcnt = (lens - 1 - idxss) + (lenn[i] - 1 - idxt[i]) - (lenn[i] - 1 - idxs[i]);
				if (lcnt < 0 || rcnt < 0 || idxtt < 0 || lent - 1 - idxtt < 0 || lens - 1 - idxss < 0 || idxss < 0) {
					continue;
				}
				if (lcnt == idxtt && rcnt == lent - 1 - idxtt) {
					cnt++;
//					printf("%d %d %d %d %d\n", i, lcnt, rcnt, idxtt, lent - 1 - idxtt);
				}
//				
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
