#include <bits/stdc++.h>
using namespace std;
const int max_n = 200001;
string s[max_n][3], t[max_n][3], xyz;
namespace my_namespace {
	int main() {
		freopen("replace.in", "r", stdin);
		freopen("replace.out", "w", stdout);
		int n, q;
		scanf("%d%d", &n, &q);
		
		for (int i = 1; i <= n; ++i) {
			getline(cin, s[i][1]);
			cin >> s[i][1] >> s[i][2];
		}
		
		for (int i = 1; i <= q; ++i) {
			getline(cin, t[i][1]);
			cin >> t[i][1] >> t[i][2];
		}
		
		for (int i = 1; i <= q; ++i) {
			int ans = 0;
			
			for (int j = 1; j <= n; ++j) {
				
				for (int k = 0; k < t[i][1].size(); ++k) {
					
					bool flag = 1;
					for (int l = k; l < k + s[j][1].size(); ++l) {
						
						if (t[i][1][l] != s[j][1][l - k]) {
							flag = 0;
							break;
						}
					}
					
					if (flag) {
						xyz = t[i][1];
						xyz.replace(k, s[j][1].size(), s[j][2]);
						if (xyz == t[i][2])
							++ans;
					}
				}
				
			}
			
			printf("%d\n", ans);
			
		}
		return 0;
	}
}
int main() {
	return my_namespace::main();
}