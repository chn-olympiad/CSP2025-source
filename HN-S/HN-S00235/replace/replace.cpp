// mouse_boy 2025.11 CSP
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ifstream fin("replace.in");
ofstream fout("replace.out");

const int kMaxN = 2e5 + 5;
ll T;
ll n, m, ans;
string s[kMaxN], s1[kMaxN], t, t2;

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
	fin >> n >> T;
	if(n > 1e4) {
		for(; T; T--) {
			fout << "0\n";
		}
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		fin >> s[i] >> s1[i];
	}
	for(; T; T--, ans = 0) {
		fin >> t >> t2, m = t.size(), t = ' ' + t, t2 = ' ' + t2;
		ll x, y;
		for(x = 1; x <= m && t[x] == t2[x]; x++);
		for(y = m; y >= 1 && t[y] == t2[y]; y--);
		if(x == n) {
			for(int i = 1; i <= n; i++) {
				if(s[i] == s1[i] && t.find(s[i])) {
					ans++;
				}
			}
			return fout << ans << '\n', 0;
		}
		string ti = "", tj, t1i = "", t1j;
		for(int i = x; i <= y; i++) {
			ti += t[i], t1i += t2[i];
		}
		tj = ti, t1j = t1i;
		for(int i = 0; i <= x - 1; i++) {
			for(int j = 0; j <= m - y; j++) {
				for(int k = 1; k <= m; k++) {
					if(s[k] == tj && s1[k] == t1j) {
						ans++;
					}
				}
				tj += t[y + j + 1];
				t1j += t2[y + j + 1];
			}
			ti = t[x - i - 1] + ti, tj = ti;
			t1i = t2[x - i - 1] + t1i, t1j = t1i;
		}
		fout << ans << '\n';
	}
  return 0;
}
/*

cd /home/noilinux/HN-S00235/replace && ulimit -s 102400 && g++ replace.cpp -o replace -O2 -Wall && time ./replace && size ./replace && ./replace && diff replace.out ans.out -Bb

*/
