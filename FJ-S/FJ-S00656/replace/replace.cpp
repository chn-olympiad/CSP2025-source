#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 2e5 + 10;
const int MOD = 998244353;
int n, q;
string s1[N], s2[N], t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		cin >> t1 >> t2;
		string ans1, ans2;
		int ans = 0;
		int len = t1.size();
		if (len != t2.size()) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			int pos = t1.find(s1[i]), l = s2[i].size() + 1;
			if (pos == -1) {
				continue;
			}
			bool f = 0;
			for (int j = 0; j < pos; j++) {
				if (t1[j] != t2[j]) {
					f = 1;
					break;
				}
			}
			for (int j = pos + l; j < len; j++) {
				if (t1[j] != t2[j]) {
					f = 1;
					break;
				}
			}
			if (f) {
				continue;
			}
			ans += (t2.substr(pos, pos + l - 1) == s2[i]);
		}
		cout << ans << "\n"; 
	}
	return 0;
}

