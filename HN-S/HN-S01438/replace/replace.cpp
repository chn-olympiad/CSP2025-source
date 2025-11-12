#include <bits/stdc++.h>
#define ull unsigned int long long

using namespace std;

const int kMaxN = 5e6 + 3, p = 131;

string s1[kMaxN], s2[kMaxN];

int n, q;

string get_s (string a, int l, int len) {
	string res = "";
	int L = a.length();
	string aa = ' ' + a;
//	cout << L << " " << aa << "\n";
	if (l + len - 1 > L) {
		return "-1";
	}
	for (int i = l, ll = 1; i <= L && ll <= len; i++, ll++) {
		res += aa[i];
//		cout << "i = " << i << " " << "n = " << n << " " << "ll = " << ll << " " << "len = " << len << "\n";
//		cout << "res = " << res << "\n";
	}
	return res;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int CSP_S1_PLS = 1; CSP_S1_PLS <= q; CSP_S1_PLS++) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.length() != t2.length()) {
			cout << "0\n";
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (s1[i].length() > t1.length()) continue;
			for (int j = 0; j < t1.length(); j++) {
				string ss = get_s (t1, j + 1, s1[i].length());
				if (ss != "-1" && ss == s1[i]) {
					string st = get_s (t2, j + 1, s1[i].length());
					if (st == s2[i]) {
//						cout << j << " " << ss << " " << s1[i] << " " << st << " " << s2[i] << "\n";
						string sss = get_s (t1, j + 1 + s1[i].length(), t1.length() - j - s1[i].length());
						string sss2 = get_s (t2, j + 1 + s2[i].length(), t2.length() - j - s2[i].length());
//						cout << sss << " " << sss2 << "\n";
						if (sss == sss2) {
							++ans;
						}
						break;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
