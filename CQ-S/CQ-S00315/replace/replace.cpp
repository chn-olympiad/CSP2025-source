#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, j, k) for (int i = j; i <= k; ++i)
unordered_map<long long, int> mp;
const int N = 5e6 + 10, mod = 5e6, M = 4e5 + 10, P = 131;
int a[N];
int p[N];
vector<int> h[M][2];
void init(string &s, int id, int j) {
	int n = s.length() - 1;
	h[j][id].resize(n + 1);
	h[j][id][0] = s[0];
	rep (i, 1, n) {
		h[j][id][i] = h[j][id][i - 1] * P + s[i];
		h[j][id][i] %= mod;
	}
}
string s[M], t[M];
bool vis[M];
int query(int id, int i, int l, int r) {
	if (l == 0) return h[i][id][r];
	long long lft = h[i][id][r], rig = h[i][id][l - 1] * p[r - l + 1] % mod;
	return (lft - rig + mod) % mod;
}
int fnds[M], fndt[M];
signed main() {
	bool f = 1;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	p[0] = 1;
	rep (i, 1, mod) p[i] = (p[i - 1] * P) % mod;
	int n, q;
	cin >> n >> q;
	rep (i, 1, n) {
		cin >> s[i] >> t[i];
		init(s[i], 0, i), init(t[i], 1, i);
		mp[1ll * h[i][0][s[i].length() - 1] * mod + h[i][1][t[i].length() - 1]] = i;
		int cnt = 0, j = 0;
		for (auto ch : s[i]) {
			if (ch != 'a' && ch != 'b') f = 0;
			if (ch == 'b') cnt++, fnds[i] = j;
			++j;
		}
		if (cnt != 1) f = 0;
		cnt = 0, j = 0;
		for (auto ch : t[i]) {
			if (ch != 'a' && ch != 'b') f = 0;
			if (ch == 'b') cnt++, fndt[i] = j;
			++j;
		}
		if (cnt != 1) f = 0;
	}
	rep (i, n + 1, n + q) {
		cin >> s[i] >> t[i];
		int cnt = 0, j = 0;
		for (auto ch : s[i]) {
			if (ch != 'a' && ch != 'b') f = 0;
			if (ch == 'b') cnt++, fnds[i] = j;
			++j;
		}
		if (cnt != 1) f = 0;
		cnt = 0, j = 0;
		for (auto ch : t[i]) {
			if (ch != 'a' && ch != 'b') f = 0;
			if (ch == 'b') cnt++, fndt[i] = j;
			++j;
		}
		if (cnt != 1) f = 0;
	}
	if (f) {
		rep (i, n + 1, n + q) {
			int ans = 0;
			rep (j, 1, n) {
				if (fnds[i] >= fnds[j] && fnds[i] - fndt[i] == fnds[j] - fndt[j] && s[j].length() - max(fndt[j], fnds[j]) <= s[i].length() - max(fndt[i], fnds[i])) ans++;
			}
			cout << ans << '\n';
		}
		return 0;
	}
	rep (i, n + 1, n + q) {
		init(s[i], 0, i), init(t[i], 1, i);
		int l = -1, r = 0;
		rep (j, 0, s[i].length() - 1) {
			if (s[i][j] != t[i][j]) {
				if (l == -1) r = j, l = j;
				else r = j;
			}
		}
		int ans = 0;
		rep (j, 0, l) {
			rep (k, r, s[i].length() - 1) {
				if (mp.count(query(0, i, j, k) * mod + query(1, i, j, k))) {
					ans += (!vis[1ll * mp[query(0, i, j, k) * mod + query(1, i, j, k)]]);
					vis[mp[1ll * query(0, i, j, k) * mod + query(1, i, j, k)]] = 1;
				}
			}
		}
		rep (j, 0, l) {
			rep (k, r, s[i].length() - 1) {
				if (mp.count(1ll * query(0, i, j, k) * mod + query(1, i, j, k))) {
					vis[1ll * mp[query(0, i, j, k) * mod + query(1, i, j, k)]] = 0;
				}
			}
		}
		cout << ans << '\n';
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a
对于特殊性质B:
存在一个 [x, y] 满足 x <= l && r - l >= y - x 
*/
