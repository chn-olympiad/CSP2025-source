#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e6 + 10;
const int mod = 998244353;

struct upd { int pre, nxt, bef, aft, pl, nl; } a[N];

unordered_map<int, unordered_map<int, vector <int>> > mp;

int n, q;

int qp (int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int inv (int a) { return qp(a, mod - 2); }

int h[N];

int hsh (int l, int r) { return (h[r] - (h[l - 1] * qp(27, r - l + 1) % mod) + mod) % mod; }

void solve () {
	cin >> n >> q;

	string s, t;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> s >> t;

		s = " " + s, t = " " + t;

		int l = 1, r = s.size() - 1, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
		
		while (s[l] == t[l]) s1 = (s1 * 27 + (s[l ++] - 'a' + 1)) % mod;
		while (s[r] == t[r]) r --;
		for (int i = r + 1 ; i < s.size() ; i ++) 
			s2 = (s2 * 27 + (s[i] - 'a' + 1)) % mod;

		for (int i = l ; i <= r ; i ++)
			s3 = (s3 * 27 + (s[i] - 'a' + 1)) % mod,
			s4 = (s4 * 27 + (t[i] - 'a' + 1)) % mod;

		a[i] = {s1, s2, s3, s4, l - 1, (int)(s.size() - 1 - r)};

		mp[s3][s4].push_back(i);
		// cerr << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << '\n';
	}

	for (int i = 1 ; i <= q ; i ++) {
		cin >> s >> t;

		s = " " + s, t = " " + t;

		// cerr << s << ' ' << t << endl;

		int s1 = 0, s2 = 0, l = 1, r = s.size() - 1;

		while (s[l] == t[l]) l ++;
		while (s[r] == t[r]) r --;

		// cerr << "NAILONG" << endl;

		for (int i = l ; i <= r ; i ++)
			s1 = (s1 * 27 + (s[i] - 'a' + 1)) % mod,
			s2 = (s2 * 27 + (t[i] - 'a' + 1)) % mod;

		// cerr << s1 << ' ' << s2 << '\n';

		h[0] = 0;
		for (int i = 1 ; i < s.size() ; i ++) 
			h[i] = (h[i - 1] * 27 + (s[i] - 'a' + 1)) % mod;

		int ll = l - 1, rr = s.size() - 1 - r, cnt = 0;

		for (auto p : mp[s1][s2]) {
			int pl = a[p].pl, nl = a[p].nl;

			if (pl > ll || nl > rr) continue;

			// cerr << l - pl << ' ' << l - 1 << ' ' << hsh(l - pl, l - 1) << '\n';
			// cerr << r + 1 << ' ' << r + nl << ' ' << hsh(r + 1, r + nl) << '\n';
			// cerr << '\n';

			if (hsh(l - pl, l - 1) == a[p].pre &&
				hsh(r + 1, r + nl) == a[p].nxt) cnt ++;
		}

		// cout << "ANS ";
		cout << cnt << '\n';
	}
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	int t = 1;
	// cin >> t;

	while (t --) solve();
}