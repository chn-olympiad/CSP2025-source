#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

const int kMaxN = 2e5 + 5, kB = 98723;

int n, q;
ULL hs[kMaxN], ht[kMaxN], h1[kMaxN], pw1[kMaxN], h2[kMaxN], pw2[kMaxN], pw[kMaxN];
string s[kMaxN][2];

ULL Get1(int l, int r) {
	return h1[r] - h1[l - 1] * pw[r - l + 1];
}

ULL Get2(int l, int r) {
	return h2[r] - h2[l - 1] * pw[r - l + 1];
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		int m = s[i][0].size();
		s[i][0] = ' ' + s[i][0], s[i][1] = ' ' + s[i][1];
		for (int j = 1; j <= m; j++) {
			hs[i] = hs[i] * kB + s[i][0][j] - 'a';
		}
		for (int j = 1; j <= m; j++) {
			ht[i] = ht[i] * kB + s[i][1][j] - 'a';
		}
	}
	pw[0] = 1;
	for (int i = 1; i <= 1e6; i++) {
		pw[i] = pw[i - 1] * kB;
	}
	for (string a, b; q--;) {
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << "0\n";
			continue;
		}
		int m = a.size();
		a = ' ' + a, b = ' ' + b;
		for (int i = 1; i <= m; i++) {
			h1[i] = h1[i - 1] * kB + a[i] - 'a';
			h2[i] = h2[i - 1] * kB + b[i] - 'a';
		}
		int ans = 0, lt = 1, rt = m;
		for (; lt <= m && a[lt] == b[lt]; lt++) {
		}
		for (; rt >= 1 && a[rt] == b[rt]; rt--) {
		}
		if (lt == 1) {
			lt--;
		}
		if (rt == m) {
			rt++;
		}
		for (int i = 1; i <= n; i++) {
			int len = s[i][0].size() - 1;
			for (int l = 1; l + len - 1 <= m; l++) {
				int r = l + len - 1;
				if (Get1(l, r) == hs[i] && Get2(l, r) == ht[i] && (l <= lt || r >= rt)) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

