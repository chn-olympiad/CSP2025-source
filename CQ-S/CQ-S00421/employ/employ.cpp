#include <bits/stdc++.h>

#define int long long

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = r; i >= l; i--)

using namespace std;

const int N = 2e5 + 5, M = 5e6 + 5, mod = 1e9 + 7, pw = 13331;

struct node {
	map<pair<int, int>, int> son;
	vector<int> pos;
	int val;
} a[M * 2];

int n, q, ans[N], gb, cnt, rt[N];

string s[N][2], t[N][2];

map<pair<int, int>, int> bl;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace.ans", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> q;
	
	rep (i, 1, n) {
		cin >> s[i][0] >> s[i][1];
	}
	
	rep (i, 1, q) {
		cin >> t[i][0] >> t[i][1];
	}
	
	rep (i, 1, q) {
		if (t[i][0].length() == t[i][1].length()) {
			int m = t[i][0].length();
			
			int l = 1, r = m;
			
			rep (j, 1, m) {
				if (t[i][0][j - 1] != t[i][1][j - 1]) {
					l = j;
					break;
				}
			}
			
			per (j, 1, m) {
				if (t[i][0][j - 1] != t[i][1][j - 1]) {
					r = j;
					break;
				}
			}
			
			int v0 = 0, v1 = 0;
			
			rep (j, l, r) {
				v0 = (v0 * pw + (t[i][0][j - 1] - 'a' + 1)) % mod;
				v1 = (v1 * pw + (t[i][1][j - 1] - 'a' + 1)) % mod;
			}
			
			if (!bl.count({v0, v1})) {
				bl[{v0, v1}] = ++gb;
				rt[gb] = ++cnt;
			}
			
			int nw = rt[bl[{v0, v1}]];
			
			rep (j, 1, max(l - 1, m - r)) {
				int ls, rs;
				
				if (l - j > 0) {
					ls = (t[i][0][l - j - 1] - 'a' + 1);
				} else {
					ls = 0;
				}
				
				if (r + j <= m) {
					rs = (t[i][0][r + j - 1] - 'a' + 1);
				} else {
					rs = 0;
				}
				
				if (!a[nw].son.count({ls, rs})) {
					a[nw].son[{ls, rs}] = ++cnt;
				}
				
				nw = a[nw].son[{ls, rs}];
			}
			
			a[nw].pos.push_back(i);
		}
	}
	
	rep (i, 1, n) {
		if (s[i][0] != s[i][1]) {
			int m = s[i][0].length();
			
			int l = 1, r = m;
			
			rep (j, 1, m) {
				if (s[i][0][j - 1] != s[i][1][j - 1]) {
					l = j;
					break;
				}
			}
			
			per (j, 1, m) {
				if (s[i][0][j - 1] != s[i][1][j - 1]) {
					r = j;
					break;
				}
			}
			
			int v0 = 0, v1 = 0;
			
			rep (j, l, r) {
				v0 = (v0 * pw + (s[i][0][j - 1] - 'a' + 1)) % mod;
				v1 = (v1 * pw + (s[i][1][j - 1] - 'a' + 1)) % mod;
			}
			
			if (!bl.count({v0, v1})) {
				continue;
			}
			
//			cout << "!" << i << " " << bl[{v0, v1}] << '\n';
			
			int nw = rt[bl[{v0, v1}]];
			
			rep (j, 1, max(l - 1, m - r)) {
				int ls, rs;
				
				if (l - j > 0) {
					ls = (s[i][0][l - j - 1] - 'a' + 1);
				} else {
					ls = 0;
				}
				
				if (r + j <= m) {
					rs = (s[i][0][r + j - 1] - 'a' + 1);
				} else {
					rs = 0;
				}
				
//				cout << i << ":" << ls << " " << rs << '\n';
				
				if (!a[nw].son.count({ls, rs})) {
					break;
				}
				
				nw = a[nw].son[{ls, rs}];
				
				if (j == max(l - 1, m - r)) {
					a[nw].val++;
				}
			}
			
			if (max(l - 1, m - r) == 0) {
				a[nw].val++;
			}
		}
	}
	
	rep (i, 1, cnt) {
		for (auto &j : a[i].son) {
			a[j.second].val += a[i].val;
		}
	}
	
	rep (i, 1, cnt) {
		for (auto j : a[i].pos) {
			ans[j] = a[i].val;
		}
	}
	
	rep (i, 1, q) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}
