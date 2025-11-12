#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
map<int, int> mp;
string tup[200005];
struct node {
	int bpos, db;
	string strc;
};
node bn[200005];
bool cmp (node u, node v) {
	if (u.db != v.db) return u.db < v.db;
	else return u.bpos < v.bpos;
}
ll _hash (string str) {
	ll t = 1;
	for (int i = 0; i < str.size (); ++ i) t = (t * 26 + (str[i] - 'a')) % mod;
	return t;
}
ll qp (int b) {
	if (b == 0) return 1;
	if (b == 1) return 26;
	ll t = qp (b >> 1) % mod;
	if (b & 1) return t * t % mod * 26 % mod;
	else return t * t % mod;
}
int cnt;
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, q;
	cin >> n >> q;
	string a, b;
	bool flg = true;
	for (int i = 1; i <= n; ++ i) {
		cin >> a >> b;
		mp[_hash (a)] = _hash (b);
		int ab = 0, bb = 0;
		for (int j = 1; j < a.size (); ++ j) {
			if (a[j] == 'b') {
				if (ab) {
					flg = false;
					break;
				}
				ab = j;
			}
			if (b[j] == 'b') {
				if (bb) {
					flg = false;
					break;
				}
				bb = j;
			}
		}
		if (flg) bn[i].bpos = ab, bn[i].db = bb - ab;
		bn[i].strc = a;
		tup[i] = a;
		//cout << bn[i].bpos << ' ' << bn[i].db << '\n';
	}
	if (flg) {
		for (int i = 1; i <= q; ++ i) {
			cnt = 0;
			string a, b;
			cin >> a >> b;
			if (a.size () != b.size ()) {
				cout << "0\n";
				continue;
			}
			int ap = a.find ('b'), bp = b.find ('b');
			sort (bn + 1, bn + n + 1, cmp);
			int l = 1, r = n;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (bn[mid].db < bp - ap) l = mid + 1;
				else r = mid;
			}
			for (int j = l; j <= n; ++ j) {
				if (bn[j].db != bp - ap) break;
				if (bn[j].bpos > ap) break;
				if (bn[j].strc.size () - bn[j].bpos - 1 > a.size () - ap - 1) continue;
				++ cnt;
			}
			cout << cnt << '\n';
		}
		return 0;
	}
	else if (n <= 1000) {
		for (int l = 1; l <= q; ++ l) {
			cnt = 0;
			cin >> a >> b;
			if (a.size () != b.size ()) {
				cout << "0\n";
				continue;
			}
			for (int i = 1; i <= n; ++ i) {
				int t = tup[i].size ();
				for (int k = 0; k + t - 1 < a.size (); ++ k) {
					bool flg = true;
					for (int j = k; j <= k + t - 1; ++ j) {
						if (a[j] != tup[i][j - k]) {
							flg = false;
							break;
						}
					}
					if (flg) {
						ll tmp = _hash (a), tmp2 = _hash (tup[i]);
						ll newhash = (tmp + (mp[tmp2] - tmp2) % mod * qp (a.size () - k - t) % mod) % mod;
						if (newhash == _hash (b)) {
							cout << i << ' ' << k << '\n';
							++ cnt;
						}
					}
				}
			}
			cout << cnt << '\n';
		}
	}
	else {
		for (int i = 1; i <= q; ++ i) cout << "0\n";
	}
	return 0;
}
/*
 * 17:01 60+0+10+8=78
 */
