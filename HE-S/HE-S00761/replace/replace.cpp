#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 9;
const int base = 131;
const int N = 5e6 + 10;

int hx[N][2];
string s[N][2];
int b[N];
inline int get(int l, int r, int op) {
	if (l > r) return 0;
	return (hx[r][op] - (hx[l - 1][op] * b[r - l + 1] % mod) + mod) % mod;
}
map <pair <int, int>, int> t;
inline int work(string s) {
	int res = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) res = (res * base % mod + (int)(s[i] - 'a' + 1)) % mod;
	return res;
}
signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	b[0] = 1;
	for (int i = 1; i <= 2005; i++) b[i] = b[i - 1] * base % mod;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0];
		int x = work(s[i][0]);
		cin >> s[i][1];
		int y = work(s[i][1]);
		t[make_pair(x, y)]++;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int m = t1.size();
		for (int i = 1; i <= m; i++) {
			hx[i][0] = (hx[i - 1][0] * base % mod + (t1[i - 1] - 'a')) % mod;
			hx[i][1] = (hx[i - 1][1] * base % mod + (t2[i - 1] - 'a')) % mod;
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (get(1, i - 1, 0) != get(1, i - 1, 1)) continue;
			for (int j = i; j <= m; j++) {
				if (get(j + 1, m, 0) != get(j + 1, m, 1)) continue;
				int x = get(i, j, 0);
				int y = get(i, j, 1);
				ans += t[make_pair(x, y)];
			}
		}
		cout << ans << '\n';
	}
}
