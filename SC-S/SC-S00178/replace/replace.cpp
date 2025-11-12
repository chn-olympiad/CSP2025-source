#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const int P = 1e9 + 7;
const int INF = 1e18;
const int base = 233;

int qpow (int u, int v) {
	if (v == 0) return 1;
	int res = 1;
	while (v) {
		if (v & 1) res = res * u % P;
		u = u * u % P;
	}
	return res;
}

int n, q, a[N], b[N], len[N];
string st[N], ed[N];

bool check (string s, string t, int frm, int x) {
	int l = s.size() - 1;
	if (frm + len[x] - 1 > l) return false;
	for (int i = 1; i <= l; i++) {
		if (frm <= i && i <= frm + len[x] - 1) continue;
		if (s[i] != t[i]) return false;
	}
	for (int i = frm; i <= frm + len[x] - 1; i++) {
		if (st[x][i - frm + 1] != s[i]) return false;
		if (ed[x][i - frm + 1] != t[i]) return false;
	}
	return true;
}

void solve1 () {
	while (q--) {
		string s, t; cin >> s >> t;
		int l = s.size(); 
		s = "?" + s; t = "?" + t;
		int ans = 0;
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= n; j++) {
				if (check (s, t, i, j)) ans++;
			}
		}
		cout << ans << "\n";
	}
}

void solve2 () {
	while (q--) {
		string s, t; cin >> s >> t;
		cout << "0\n";
	}
}

void solve () {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> st[i] >> ed[i];
		len[i] = st[i].size();
		st[i] = "?" + st[i];
		ed[i] = "?" + ed[i];
	}
	if (n <= 1000) solve1();
	else solve2();
}

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; // cin >> T;
	while (T--) solve ();
	return 0;
}