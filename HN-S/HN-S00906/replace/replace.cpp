#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N], rs[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i] >> rs[i];
	}
	while(q --) {
		string x, rx;
		cin >> x >> rx;
		x = ' ' + x; rx = ' ' + rx;
		int ans = 0;
		if(x.size() != rx.size()){
			cout << 0 << '\n';
			continue;
		}
		for(int len = 1; len <= x.size(); len ++) {
			for(int l = 1; l + len - 1 <= x.size(); l ++) {
				int r = l + len - 1;
				bool f = 1;
				for(int i = 1; i <= l - 1; i ++) {
					if(x[i] != rx[i]) {
						f = 0; break;
					}
				}
				for(int i = r + 1; i <= x.size(); i ++) {
					if(x[i] != rx[i]) {
						f = 0; break;
					}
				}
				if(!f) continue;
				string tmp = "", ctmp = "";
				for(int i = l; i <= r; i ++) {
					tmp += x[i];
					ctmp += rx[i];
				}
				for(int i = 1; i <= n; i ++) {
					if(tmp == s[i] && ctmp == rs[i]) {
//						cout << i << '\n';
						++ ans;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
