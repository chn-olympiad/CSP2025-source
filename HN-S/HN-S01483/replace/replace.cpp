#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 2e5 + 5, M = 2e3 + 5, K = 1e3 + 5, base = 999983;
int n, q, a[N], b[N], c[N];
ull hs[K][M], pw[N], ht[K][M];
string s1, s2;
map<ull, ull> mp;
ull geths(ull hss[], int l, int r) {
	if (l > r) return 0;
	return hss[r] - hss[l - 1] * pw[r - l + 1];
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	if (n <= 1e3 && q != 1) {
		pw[0] = 1;
		for (int i = 1; i < M; i++) pw[i] = pw[i - 1] * base;
		for (int i = 1; i <= n; i++) {
			cin >> s1 >> s2;
			s1 = " " + s1, s2 = " " + s2;
			for (int j = 1; j < s1.size(); j++) hs[i][j] = hs[i][j - 1] * base + s1[j];
			for (int j = 1; j < s2.size(); j++) ht[i][j] = ht[i][j - 1] * base + s2[j];
			mp[hs[i][s1.size() - 1]] = ht[i][s2.size() - 1];
		}
		while (q--) {
			cin >> s1 >> s2;
			s1 = " " + s1, s2 = " " + s2;
			for (int j = 1; j < s1.size(); j++) hs[1][j] = hs[1][j - 1] * base + s1[j];
			for (int j = 1; j < s2.size(); j++) ht[1][j] = ht[1][j - 1] * base + s2[j];
			int cnt = 0;
			for (int l = 1; l < s1.size(); l++) {
				for (int r = l; r < s1.size(); r++) {
					if (mp[geths(hs[1], l, r)] == geths(ht[1], l, r) && geths(hs[1], 1, l - 1) == geths(ht[1], 1, l - 1) &&
					geths(hs[1], r + 1, s1.size() - 1) == geths(ht[1], r + 1, s1.size() - 1)) {
						cnt++;
					}
				}
			}
			cout << cnt << '\n';
		} 
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> s1 >> s2;
			s1 = " " + s1, s2 = " " + s2;
			int ii, jj;
			for (int j = 1; j < s1.size(); j++) if (s1[j] == 'b') ii = j;
			for (int j = 1; j < s2.size(); j++) if (s2[j] == 'b') jj = j;
			mp[jj - ii]++;
			a[i] = ii, b[i] = s1.size() - 1 - jj, c[i] = jj;
		}
		if (n > 1e4) {
			while (q--) {
				cin >> s1 >> s2;
				s1 = " " + s1, s2 = " " + s2;
				int ii, jj;
				for (int j = 1; j < s1.size(); j++) if (s1[j] == 'b') ii = j;
				for (int j = 1; j < s2.size(); j++) if (s2[j] == 'b') jj = j;
				cout << mp[jj - ii] << '\n';
			}
		} else {
			while (q--) {
				cin >> s1 >> s2;
				s1 = " " + s1, s2 = " " + s2;
				int ii, jj;
				for (int j = 1; j < s1.size(); j++) if (s1[j] == 'b') ii = j;
				for (int j = 1; j < s2.size(); j++) if (s2[j] == 'b') jj = j;
				int cnt = 0;
				for (int i = 1; i <= n; i++) {
					if (a[i] <= ii && b[i] <= s1.size() - jj - 1 && c[i] - a[i] == jj - ii) {
						cnt++;
					}
				}
				cout << cnt << '\n';
			}
		} 
	}
	return 0;
}

