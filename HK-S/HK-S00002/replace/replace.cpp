#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	vector<string> s1(n+1,""), s2(n+1,"");
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	map<string, int> mp;
	for (int i = 1; i <= n; i++) mp[s1[i]] = i;
	while (q--) {
		string t1, t2; cin >> t1 >> t2;
		int way = 0;
		if (t1.length() != t2.length()) {
			cout << 0 << '\n';
			continue;
		}
		for (int l = 0; l < (int)t1.length(); l++) {
			for (int r = l; r < (int)t1.length(); r++) {
				string te1 = "", te2 = "";
				for (int j = l; j <= r; j++) te1 += t1[j];
				for (int i = 1; i <= n; i++) 
					if (te1 == s1[i]) {
						string temp = s2[i];
						for (int i = l-1; i >= 0; i--) temp = t1[i] + temp;
						for (int i = r+1; i < (int)(t1.length()); i++) temp = temp + t1[i];
						way += (temp == t2);
					}
				}
			}
		cout << way << '\n';
	}
	return 0;
}
