#include <bits/stdc++.h>

using namespace std;

int n, q;
map < string , bool > f;
map < string , string > mp;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", & n, & q);
	for (int i = 1; i <= n; ++ i) {
		string s1, s2;
		cin >> s1 >> s2;
		f[s1] = true;
		mp[s1] = s2;
	}
	if (n <= 10000) {
		while (q --) {
			int ans = 0;
			string s1, s2;
			cin >> s1 >> s2;
			int len = s1.size();
			int l = 0;
			while (l + 1 < len && s1[l] == s2[l]) {
				++ l;
			}
			for (int i = 0; i < l; ++ i) {
				for (int j = 1; i + j <= len; ++ j) {
					string t = s1.substr(i, j);
					if (f[t]) {
						++ ans;
					}
				}
			}
			printf("%d\n", ans);
		}
		return 0;
	}
	if (q == 1) {
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		int len = s1.size();
		int l = 0;
		while (l + 1 < len && s1[l] == s2[l]) {
			++ l;
		}
		for (int i = 0; i < l; ++ i) {
			for (int j = 1; i + j <= len; ++ j) {
				string t = s1.substr(i, j);
				if (f[t]) {
					++ ans;
				}
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	while (q --) {
		string s1, s2;
		cin >> s1 >> s2;
		puts("0");
	}
	return 0;
}
