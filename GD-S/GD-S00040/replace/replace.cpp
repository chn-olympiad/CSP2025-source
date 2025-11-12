#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
const int N = 5000005;
using namespace std;

int T;
int n, q;
string r1[N], r2[N];
int pre1[N], pre2[N];
int val1[N], val2[N];

int base[N], p = 131, mod = 998244353;
void Hashprx1(string s) {
	base[0] = 1;
	pre1[0] = s[0];
	for (int i = 1; i < s.length(); i++) {
		base[i] = base[i - 1] * p % mod;
		pre1[i] = (pre1[i - 1] * p + s[i]) % mod;
	}
}

void Hashprx2(string s) {
	base[0] = 1;
	pre2[0] = s[0];
	for (int i = 1; i < s.length(); i++) {
		base[i] = base[i - 1] * p % mod;
		pre2[i] = (pre2[i - 1] * p + s[i]) % mod;
	}
}

int qry1(int l, int r) {
	if (l == 0)
		return pre1[r];
	if (l > r)
		return 0;
	return ((pre1[r] - pre1[l - 1] * base[r - l + 1]) % mod + mod) % mod;
}

int qry2(int l, int r) {
	if (l == 0)
		return pre2[r];
	if (l > r)
		return 0;
	return ((pre2[r] - pre2[l - 1] * base[r - l + 1]) % mod + mod) % mod;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> r1[i] >> r2[i];
	for (int i = 1; i <= n; i++) {
		val1[i] = r1[i][0];
		for (int j = 1; j < r1[i].length(); j++)
			val1[i] = (val1[i] * p + r1[i][j]) % mod;
		val2[i] = r2[i][0];
		for (int j = 1; j < r2[i].length(); j++)
			val2[i] = (val2[i] * p + r2[i][j]) % mod;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.length();
		if (t1.length() != t2.length()) {
			cout << "0\n";
			continue;
		}
		
		Hashprx1(t1), Hashprx2(t2);
//		cout << val1[4] << endl; 
//		cout << pre1[1] << endl;
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int l = r1[i].length();
			if (l > len)
				continue;
			for (int j = 0; j < len; j++) {
//				cout << j + l << ' ' << len - 1 << endl;
				if (qry1(j + l, len - 1) == qry2(j + l, len - 1)) {
					if (qry1(j, j + l - 1) == val1[i] && 
						qry2(j, j + l - 1) == val2[i]) {
//							cout << j << endl;
						ans++;
					}
				}

				if (qry1(0, j) != qry2(0, j))
					break;
			}
				

		}
		cout << ans << endl;
	}
	return 0;
}
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a


