#include<bits/stdc++.h>
#define int long long
using namespace std;
const int max_n = 2e5 + 5;

int n, q;

string s[max_n][2];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
	}
	
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		
		int ans = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= t1.size() - s[i][0].size(); j++) {
						
				int x = 1;
				for (int k = j; k < j + s[i][0].size(); k++) {
					if (s[i][0][k] != t1[k] || s[i][1][k] != t2[k]) {
						x = 0;
						break; 
					}
				}
				for (int k = j + s[i][0].size(); k < t1.size(); k++) {
					if (t1[k] != t2[k]) {
						x = 0;
						break;
					}
				}
				
				if (x) 
					ans++;
				else if (t1[j] != t2[j])
					break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}