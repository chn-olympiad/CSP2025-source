#include<bits/stdc++.h>

#define rep(i, s, e) for(int (i) = (s); (i) <= (e); ++(i))
#define fep(i, s, e) for(int (i) = (s); (i) < (e); ++(i))
#define _rep(i, s, e) for(int (i) = (s); (i) >= (e); --(i))
#define _fep(i, s, e) for(int (i) = (s); (i) > (e); --(i))

// #define int long long
#define pii pair<int, int>

using namespace std;

constexpr int inf = numeric_limits<int>::max() / 2;
constexpr int ninf = numeric_limits<int>::min() / 2;
constexpr int mod = 998442853;
constexpr double eps = 1e-9;

void get(string x, string y, string &a, string &b, string &c, string &d) {
	a = b = c = d = "";
	int len = x.size();
	int l = len, r = 0;
	fep(j, 0, len) {
		if(x[j] == y[j]) {
			a += x[j];
		} else {
			l = j;
			break;
		}
	}
	reverse(a.begin(), a.end());
	_rep(j, len - 1, l) {
		if(x[j] == y[j]) {
			d += x[j];
		} else {
			r = j;
			break;
		}
	}
	reverse(d.begin(), d.end());
	b = x.substr(l, r - l + 1);
	c = y.substr(l, r - l + 1);
	return;
}

int hsh(string s) {
	int ans = 0;
	for(auto ch : s) {
		ans = (131ll * ans % mod + (ch - 'a' + 1)) % mod;
	}
	return ans;
}

int n, q, lena[200005], lenb[200005], hsha[200005], hshb[200005], hsh1[200005], hsh2[200005];
map<pair<string, string>, vector<int>> mp;

void solve() {
	cin >> n >> q;
	rep(i, 1, n) {
		string x, y, a, b, c, d;
		cin >> x >> y;
		if(x == y) continue;
		get(x, y, a, b, c, d);
		lena[i] = a.size();
		lenb[i] = d.size();
		hsha[i] = hsh(a);
		hshb[i] = hsh(d);
		mp[{b, c}].push_back(i);
	}
	while(q--) {
		string x, y, a, b, c, d;
		cin >> x >> y;
		if(x.size() != y.size()) {
			cout << 0 << endl;
			continue;
		}
		get(x, y, a, b, c, d);
		hsh1[0] = 0;
		int len1 = a.size();
		rep(i, 1, len1) {
			hsh1[i] = (131ll * hsh1[i - 1] % mod + (a[i - 1] - 'a' + 1)) % mod;
		}
		hsh1[0] = 0;
		int len2 = d.size();
		rep(i, 1, len2) {
			hsh2[i] = (131ll * hsh2[i - 1] % mod + (d[i - 1] - 'a' + 1)) % mod;
		}
		int ans = 0;
		for(auto i : mp[{b, c}]) {
			if(lena[i] > len1) continue;
			if(lenb[i] > len2) continue;
			if(hsh1[lena[i]] != hsha[i]) continue;
			if(hsh2[lenb[i]] != hshb[i]) continue;
			++ans;
		}
		cout << ans << endl;
	}
	return;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}