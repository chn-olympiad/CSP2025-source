#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 5;
int n , q , nxt[5000005] , len;
string s1[N] , s2[N];
void KMP(const string &s) {
	nxt[0] = nxt[1] = 0;
	for (int i = 2 , j = 0; i <= len; i++) {
		while(j && s[i] != s[j + 1]) j = nxt[j];
		if (s[i] == s[j + 1]) ++j;
		nxt[i] = j;
	}
}
signed main() {
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		s1[i] = ' ' + s1[i] , s2[i] = ' ' + s2[i];
	}
	for (int i = 1; i <= q; i++) {
		string t1 , t2; cin >> t1 >> t2;
		int L = t1.size();
		t1 = ' ' + t1 , t2 = ' ' + t2;
		int st = -1 , ed = -1;
		for (int j = 1; j <= n; j++) {
			if (t1[j] != t2[j]) {
				st = j; break;
			}
		}
		for (int j = n; j >= 1; j--) {
			if (t1[j] != t2[j]) {
				ed = j; break;
			}
		}
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			bool f1 = 0 , f2 = 0;
			len = s1[j].size() - 1;
			KMP(s1[j]);
			for (int k = 1 , p = 0; k <= L; k++) {
				while(p && t1[k] != s1[j][p + 1]) p = nxt[p];
				if (t1[k] == s1[j][p + 1]) p++;
				if (p == len && k - len + 1 <= st && k <= ed) {
					f1 = 1; break;
				}
			}
			KMP(s2[j]);
			for (int k = 1 , p = 0; k <= L; k++) {
				while(p && t2[k] != s2[j][p + 1]) p = nxt[p];
				if (t2[k] == s2[j][p + 1]) p++;
				if (p == len && k - len + 1 <= st && k <= ed) {
					f2 = 1; break;
				}
			}
			ans += f1 & f2;
		}
		cout << ans << '\n';
	}
	return 0;
}

