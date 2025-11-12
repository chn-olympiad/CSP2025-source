#include <bits/stdc++.h>
using namespace std;

int n, q;
map<string, string> s;
string t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		s[s1] = s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		int l1 = t1.size(), l2 = t2.size();
		if (l1 != l2) {
			puts("0");
			continue;
		}
		int cnt = 0, len = 0;
		bool b = false;
		for (int i = 0; i < l1; i++) {
			if (t1[i] != t2[i]) {
				if (b == false)
					cnt++, len = 0;
				b = true;
				len++;
			} else
				b = false;
		}
		if (cnt > 1) {
			puts("0");
			continue;
		}
		int ans = 0;
		for (int i = 0; i < l1; i++)
			for (int j = len; j <= l1 - i; j++) {
				string sub = t1.substr(i, j),
					sub2 = t2.substr(i, j);
				if (s.find(sub) == s.end())
					continue;
				string ts1 = t1;
				ts1.replace(i, j, s.find(sub) -> second);
				if (ts1 == t2)
					ans++;
			}
		printf("%d\n", ans);
	}
}