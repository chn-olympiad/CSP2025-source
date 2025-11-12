#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
#define pb push_back
#define vi vector <int>
#define R(i, l, r) for (int i = (l); i <= (r); ++i)
#define debug cout << "-------------------------------\n"

const int N = 2e5 + 5, L = 5e6 + 5, P = 998244353;
int n, q, bs = 131;
string s1[N], s2[N]; int lens[N];
string t1[N], t2[N]; int lent[N];
vi ch[N][26];
unsigned now1[L], now2[L];
vector <unsigned> hsh1[N], hsh2[N];
int l, r, idx;
unsigned qw[L];
int calct(int l, int r, unsigned *now) {
	int len = r - l + 1; 
	return now[r] - (l ? now[l - 1] : 0) * qw[len];
}
int calcs(int l, int r, vector<unsigned> hsh) {
	int len = r - l + 1;
	return hsh[r] - (l ? hsh[l - 1] : 0) * qw[len];
}
int ans = 0;
void match() {
	int len = r - l + 1;
	int p1 = calct(l, r, now1), p2 = calct(l, r, now2);;
	int c = t1[idx][l] - 'a';
	R(i, 1, n) {
		int t;
		for (int j : ch[i][c]) {
			if (j + len - 1 >= lens[i]) break;
			if (l < j) continue;
			t = lens[i] - 1 - (j + len) + 1;
			if (r + t - 1 >= lent[idx]) continue;
			if (j > 0 && s2[i][0] != t1[idx][l - j]) continue;
			if (j > 1 && s2[i][1] != t1[idx][l - j + 1]) continue;
//			if (j + len + t - 1 < lens[i]) {
//				if (s2[i][j + len] != t1[idx][r + 1]) continue;
//			}
			if (calcs(j, j + len - 1, hsh1[i]) == p1 && calcs(j, j + len - 1, hsh2[i]) == p2) {
				bool flg1 = 0, flg2 = 0;
				if (!j) flg1 = 1;
				if (j > 0) {
					if (calcs(0, j - 1, hsh2[i]) == calct(l - j, l - 1, now1)) {
						flg1 = 1;
					}
				}
				if (!flg1) continue;
				t = lens[i] - 1 - (j + len) + 1;
				if (j + len + t - 1 < lens[i]) {
					if (calcs(j + len, j + len + t - 1, hsh2[i]) == calct(r + 1, r + t, now1)) {
						flg2 = 1;
					}
				} else {
					flg2 = 1;
				}
				if (flg1 && flg2) {
					++ans;
				}
			}
//		}
		}
	}
}
void solve1() {
	R(i, 1, q) {
		idx = i;
		l = -1, r = -1;
		if (t1[i].size() != t2[i].size()) {
			cout << 0 << '\n';
			continue;
		}
		R(j, 0, lent[i] - 1) {
			if (t1[i][j] != t2[i][j]) {
				l = j;
				break;
			}
		}
		for (int j = lent[i] - 1; j >= 0; --j) {
			if (t1[i][j] != t2[i][j]) {
				r = j;
				break;
			}
		}
//		cout << l << ' ' << r << endl;
		R(j, 0, lent[i]) {
			now1[j] = (j ? now1[j - 1] : 0) * bs + t1[i][j] - 'a';
			now2[j] = (j ? now2[j - 1] : 0) * bs + t2[i][j] - 'a';
		}
		match();
		cout << ans << '\n';
		ans = 0;
	}
}
vector<PII> wr[2][N];
void solve2() {
	R(i, 1, n) {
		l = -1, r = -1;
		R(j, 0, lent[i] - 1) {
			if (s1[i][j] != s2[i][j]) {
				l = j;
				break;
			}
		}
		for (int j = lent[i] - 1; j >= 0; --j) {
			if (s1[i][j] != s2[i][j]) {
				r = j;
				break;
			}
		}
		int op = 1;
		if (s1[i][l] == 'b') op = 0;
		wr[op][r - l + 1].pb({l, lens[i] - r - 1});
	}
	R(i, 1, q) {
		if (t1[i].size() != t2[i].size()) {
			cout << 0 << '\n';
			continue;
		}
		l = -1, r = -1;
		R(j, 0, lent[i] - 1) {
			if (t1[i][j] != t2[i][j]) {
				l = j;
				break;
			}
		}
		for (int j = lent[i] - 1; j >= 0; --j) {
			if (t1[i][j] != t2[i][j]) {
				r = j;
				break;
			}
		}
		int op = 1;
		if (t1[i][l] == 'b') op = 0;
		int fk = r - l + 1;
		if (!wr[op][fk].size()) {
			cout << 0 << '\n';
		} else {
			ans = 0;
			for (auto it : wr[op][fk]) {
				if (it.first <= l && it.second <= lent[i] - r - 1) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("1.txt", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> q; 
	qw[0] = 1;
	int mx = 0;
	R(i, 1, n) {
		cin >> s1[i] >> s2[i];
		lens[i] = s1[i].size();
		hsh1[i].assign(lens[i], 0);
		hsh2[i].assign(lens[i], 0);
		R(j, 0, lens[i] - 1) {
			hsh1[i][j] = (j ? hsh1[i][j - 1] : 0) * bs + s1[i][j] - 'a';
			hsh2[i][j] = (j ? hsh2[i][j - 1] : 0) * bs + s2[i][j] - 'a';
			ch[i][s1[i][j] - 'a'].pb(j);
		}
		mx = max(mx, lens[i]);
	}
	R(i, 1, q) {
		cin >> t1[i] >> t2[i];
		lent[i] = t1[i].size();
		mx = max(mx, lent[i]);
	}
	R(i, 1, mx + 1) { // !!!
		qw[i] = qw[i - 1] * 131;		
	}
	int op = 1;
	R(i, 1, n) {
		int c1 = 0, c2 = 0;
		R(j, 0, lens[i] - 1) {
			if (s1[i][j] == 'a') {
				++c1;
			} else if (s1[i][j] == 'b') {
				++c2;
			}
		}
		if (c1 + c2 != lens[i] || c2 != 1) {
			op = 0;
		}
	}
//	cout << op << endl;
//	if (op) {
//		solve2();
//	}
	op = 1;
	if (q <= 1 || n <= 2000 || op) {
		solve1();
	}
    return 0;
}

