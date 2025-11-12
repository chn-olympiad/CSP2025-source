#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
map<string, string> mp;
int f[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int l1 = s1.length();
		f[l1] = 1;
		mp[s1] = s2;
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		int l1 = t1.length(), l2 = t2.length();
		if (l1 != l2) {
			printf("0\n");
			continue;
		}
		int l = -1, r = -1;
		for (int i = 0; i < l1; i++) {
			if (t1[i] != t2[i]) {
				l = i;
				break;
			}
		}
		for (int i = l1 - 1; i >= 0; i--) {
			if (t1[i] != t2[i]) {
				r = i;
				break;
			}
		}
		int tot = 0;
		for (int i = 0; i <= l; i++) {
			for (int j = r; j < l1; j++) if (f[j - i + 1]) {
				string sa = "", sb = "", sc = "";
				for (int k = 0; k < i; k++) {
					sa += t1[k];
				}
				for (int k = i; k <= j; k++) {
					sb += t1[k];
				}
				for (int k = j + 1; k < l1; k++) {
					sc += t1[k];
				}
				string t = sa + mp[sb] + sc;
				if (t == t2) {
					tot++;
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
} 
