#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, Q, hs1[5000010], hs2[5000010], p[5000010], wc = 37;
vector <int> hs[2][200010];
string s1[200010], s2[200010];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i];
		cin >> s2[i];
	}
	while (Q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			printf("0\n");
			continue;
		}
		string now = "";
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (t1.size() < s1[i].size()) continue;
			for (int j = 0; j + s1[i].size() - 1 < t1.size(); j++) {
				string tt = "";
				tt += t1.substr(j, s1[i].size());
				if (tt == s1[i]) {
					string ss = "";
					ss += t1.substr(0, j) + s2[i] + t1.substr(j + s2[i].size(), t1.size() - (j + s2[i].size()) + 1);
					if (ss == t2) ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
}
