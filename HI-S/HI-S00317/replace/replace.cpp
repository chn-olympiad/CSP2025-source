#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

long long n, q, ans;
string s[200005][3], t[200005][3];

int main() {
	freopen("replace.in", "r", stdin);
	// freopen("replace.out", "w", stdout);
	scanf("%lld %lld", &n, &q);
	for (int i=1; i<=n; i++) {
		// scanf("%s %s", &s[i][1], &s[i][2]);
		cin >> s[i][1] >> s[i][2];
	}
	for (int p=1; p<=q; p++) {
		// scanf("%s %s", &t[p][1], &t[p][2]);
		cin >> t[p][1] >> t[p][2];
		ans = 0;
		
		if (t[p][1].size() != t[p][2].size()) {
			cout << "0\n";
			continue;
		}
		
		long long len = t[p][1].size();
		for (int i=0; i<len; i++) {
			for (int j=i; j<len; j++) {
				if (t[p][1].substr(0, i) != t[p][2].substr(0, i) || t[p][1].substr(j+1, len-j-1) != t[p][2].substr(j+1, len-j-1)) continue;
				for (int k=1; k<=n; k++) {
					if (s[k][1].size() > len) continue;
					if (t[p][1].substr(i, j-i+1) == s[k][1] &&
						t[p][2].substr(i, j-i+1) == s[k][2]) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

