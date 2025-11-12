#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, base = 114514451, mod = 1e9 + 7, L = 5e6 + 5;

string s[N][2], t[N][2];
struct Str {
	string s;
	vector<int> hsh;
} ss[N][2], tt[N][2];
int mi[N * 30];

void init(int n, int q) {
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			int m = s[i][j].length();
			s[i][j] = ' ' + s[i][j];
			ss[i][j].s = s[i][j], ss[i][j].hsh.resize(m + 1);
			ss[i][j].hsh[0] = 0;
			for(int k = 1; k <= m; k++)
				ss[i][j].hsh[k] = (ss[i][j].hsh[k - 1] * base % mod + s[i][j][k]) % mod;
		}
	}
	for(int i = 1; i <= q; i++) {
		for(int j = 0; j < 2; j++) {
			int m = t[i][j].length();
			t[i][j] = ' ' + t[i][j];
			tt[i][j].s = t[i][j], tt[i][j].hsh.resize(m + 1);
			tt[i][j].hsh[0] = 0;
			for(int k = 1; k <= m; k++)
				tt[i][j].hsh[k] = (tt[i][j].hsh[k - 1] * base % mod + t[i][j][k]) % mod;
		}
	}
	mi[0] = 1; for(int i = 1; i <= L - 5; i++) mi[i] = mi[i - 1] * base % mod;
}

int get_hsh(vector<int>& hsh, int l, int r) { return (hsh[r] - hsh[l - 1] * mi[r - l + 1] % mod + mod) % mod; }

pair<int, int> get_hsh(bool op, int idx, int l, int r) {
	if(op) return { get_hsh(ss[idx][0].hsh, l, r), get_hsh(ss[idx][1].hsh, l, r) };
	else return { get_hsh(tt[idx][0].hsh, l, r), get_hsh(tt[idx][1].hsh, l, r) };
}

bool check(int s_ind, int t_ind, int l, int r) {
	int slen = s[s_ind][0].length() - 1;
	int tlen = t[t_ind][0].length() - 1;
	if(r - l + 1 > slen) return 0;
	for(int i = 1; i <= min(slen, slen - (r - l + 1) + 1); i++) {
		int ll = (l - i + 1), rr = ll + slen - 1;
		if(ll <= 0 || rr > tlen) continue;
		if(get_hsh(1, s_ind, 1, slen) == get_hsh(0, t_ind, ll, rr)) return 1;
	}
	return 0;
}

int l[N], r[N];

void solve() {
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for(int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1];
	init(n, q);
	for(int i = 1; i <= q; i++) {
		for(int j = 1; j < t[i][0].length(); j++) {
			if(t[i][0][j] != t[i][1][j]) { l[i] = j; break; }
		}
		for(int j = t[i][0].length() - 1; j >= 1; j--) {
			if(t[i][0][j] != t[i][1][j]) { r[i] = j; break; }
		}
	}
	for(int i = 1; i <= q; i++) {
		int ans = 0;
		if(t[i][0].length() == t[i][1].length()) {
			for(int j = 1; j <= n; j++) {
				ans += check(j, i, l[i], r[i]);
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/