#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
map<string, multiset<string> > mp;

void solve() {
	string t1, t2;
	cin >> t1 >> t2;
	int n = t1.size();
	if (n != (int)t2.size()) {
		printf("0\n");
		return;
	}
	int s = 0, e = n - 1;
	for (int i = 0; i < n; i++) {
		if (t1[i] != t2[i]) {
			s = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (t1[i] != t2[i]) {
			e = i;
			break;
		}
	}
	ll ans = 0;
	string ss = t1.substr(s, e - s + 1);
	string ssss = t2.substr(s, e - s + 1);
	for (int i = s; i >= 0; i--) {
		string sss = ss;
		string sssss = ssss;
		for (int j = e; j < n; j++) {
			ans += mp[sss].count(sssss);
			if (j < n - 1) {
				sss = sss + t1[j + 1];
				sssss = sssss + t2[j + 1];
			}
		}
		if (i) ss = t1[i - 1] + ss;
		if (i) ssss = t2[i - 1] + ssss;
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		mp[s1].insert(s2);
	}
	while (q--) solve();
	return 0;
}
/*
4 2
xabcx
xadex
ab
cd
bc
de
aa
bb
xabcx
xadex
aaaa bbbb
*/
