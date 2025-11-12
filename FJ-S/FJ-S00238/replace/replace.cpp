#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5 + 10;
struct str_ {
	string s1, s2;
}str[N];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> str[i].s1 >> str[i].s2;
	for(int i = 1; i <= q; i++) {
		int ans = 0;
		string str1, str2;
		cin >> str1 >> str2;
		for(int j = 1; j <= n; j++) {
			int site = str1.find(str[j].s1);
			if(site >= 0 && site < str1.length()) {
				if(site == 0) {
					goto go2;
				}
				else {
					for(int i = 0; i < site; i++) {
						if(str1[i] != str2[i]) {
							goto go1; 
						}
					}
				}
				go2:;
				for(int i = 0; i < str[j].s1.length(); i++) {
					if(str[j].s2[i] != str2[i + site]) {
						goto go1;
					}
				}
				if(site + str[j].s1.length() == str1.length() - 1) {
					if(str1[site + str[j].s1.length()] != str2[str1.length() - 1]) {
							goto go1; 
					}
				}
				else {
					for(int i = site + str[j].s1.length() + 1; i < str1.length(); i++) {
						if(str1[i] != str2[i]) {
							goto go1;
						}
					}
				}
				ans++;
			}
			go1:;
		}
		cout << ans << endl;
	}
	return 0;
} 
