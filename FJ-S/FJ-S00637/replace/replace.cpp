#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, q; string s[N][2];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for (string t1, t2, t3; q--; ) {
		cin >> t1 >> t2;
		int ans = 0, len = t1.size();
		if (len != t2.size()) { putchar(48), putchar('\n'); continue; }
		for (int i = 1, j, k, k0 = 0, k0_ = -1, len2; i <= n; i++) {
			bool fl = false; len2 = s[i][0].size();
			for (j = k0, k = 0; j < len; j++) {
				if (t1[j] == s[i][0][k]) k++;
				else k0 = j + 1, k = 0;
				if (k == len2) { fl = true; break; }
			}
			if (!fl) { k0 = 0; continue; }
			if (!k0) {
				t3 = s[i][1];
				for (j = k0 + len2; j < len; j++) t3 += t1[j];
			} else {
				t3 = "";
				for (j = 0; j < k0; j++) t3 += t1[j];
				t3 += s[i][1];
				for (j = k0 + len2; j < len; j++) t3 += t1[j];
			}
			if (t3 == t2) ans++, k0 = 0, k0_ = -1;
			else if (k0 > k0_) k0_ = k0++, i--;
		}
		cout << ans << '\n';
	}
}
