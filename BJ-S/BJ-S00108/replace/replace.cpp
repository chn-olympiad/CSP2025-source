#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 2e5, MAXM = 5e6, BASE = 131, INF = 0x3f3f3f3f;
int n, q, l1, l2;
ull pw[MAXM + 5];
bool all_special = 1;
string s1[MAXN + 5], s2[MAXN + 5], t1[MAXN + 5], t2[MAXN + 5];
unordered_map<ull, int> cnt;
inline ull clip(ull hsh[], int l, int r) {
	return hsh[r] - hsh[l - 1] * pw[r - l + 1];
}
inline bool is_special(string &s) {
	bool flg = 0;
	for (int i = 1; i < s.size(); i ++) {
		if (s[i] != 'a' && s[i] != 'b') return 0;
		if (s[i] == 'b') {
			if (flg) return 0;
			flg = 1;
		}
	}
	return 1;
}
namespace sub1 {
	ull hsh[MAXM + 5];
	inline void solve() {
		for (int k = 1; k <= q; k ++) {
			int mn = INF, mx = ~INF;
			for (int i = 1; i < t1[k].size(); i ++) {
				hsh[i] = hsh[i - 1] * BASE * BASE + t1[k][i] * BASE + t2[k][i];
				if (t1[k][i] != t2[k][i]) {
					mn = min(mn, i);
					mx = max(mx, i);
				}
			}
			ll ans = 0;
			for (int i = 1; i <= mn; i ++)
				for (int j = mx; j < t1[k].size(); j ++)
					ans += cnt[clip(hsh, i, j)];
			cout << ans << '\n';
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	pw[0] = 1;
	for (int i = 1; i <= MAXM; i ++) pw[i] = pw[i - 1] * BASE * BASE;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> s1[i] >> s2[i];
		s1[i] = " " + s1[i];
		s2[i] = " " + s2[i];
		all_special &= is_special(s1[i]);
		all_special &= is_special(s2[i]);
		ull hsh = 0;
		for (int j = 1; j < s1[i].size(); j ++)
			hsh = hsh * BASE * BASE + s1[i][j] * BASE + s2[i][j];
		cnt[hsh] ++;
	}
	for (int i = 1; i <= q; i ++) {
		cin >> t1[i] >> t2[i];
		t1[i] = " " + t1[i];
		t2[i] = " " + t2[i];
		all_special &= is_special(t1[i]);
		all_special &= is_special(t2[i]);
	}
	sub1::solve();
	return 0;
}
