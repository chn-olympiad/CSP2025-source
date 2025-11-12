#include <bits/stdc++.h>
using namespace std;

int n, q;
map<string, string> m;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		m[s1] = s2;
	}
	while (q--) {
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				string y;
				for (int k = i; k <= j; k++) {
					y += s1[k];
				}
				if (m.count(y)) y = m[y];
				string x;
				for (int k = 0; k < i; k++) {
					x += s1[k];
				}
				string z;
				for (int k = j + 1; k < len; k++) {
					z += s1[k];
				}
				if (x + y + z == s2) ans++;
			}
		}
		printf("%d", ans);
	}
	return 0;
}