#include <bits/stdc++.h> 
#define ll long long
using namespace std;

namespace Creeper{
	const int N = 2e5 + 5;
	int n, m;
	string s[N], t[N]; 
	string a[N], b[N];
	map<string, string> mp;
	void solve() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> s[i] >> t[i], mp[s[i]] = t[i];
		for (int i = 1; i <= m; i++) {
			string strs, strt;
			cin >> strs >> strt;
			int ans = 0;
		
			for (int i = strs.size(); i >= 1; i--) {
				a[i] = a[i + 1] + strs[i - 1];
//				cout << a[i] << ' ';
			} 
//			cout << '\n';
			for (int i = strt.size(); i >= 1; i--) {
				b[i] = b[i + 1] + strt[i - 1];
//				cout << b[i] << ' ';
			}  
//			cout << '\n';
			for (int i = 0; i < strs.size(); i++) {
				if (i >= 1 && strs[i - 1] != strt[i - 1]) break;
				string tmps = "", tmpt = "";
				tmps.push_back(strs[i]);
				tmpt.push_back(strt[i]);
				for (int j = i + 1; j < strs.size(); j++) {
					tmps.push_back(strs[j]);
					tmpt.push_back(strt[j]);
					if (a[j + 2] == b[j + 2]) { 
//						cout << i << ' ' << j << ' ' << a[j + 2] << ' ' << b[j + 2] << '\n';
//						cout << tmps << ' ' << tmpt << '\n';
						if (mp[tmps] == tmpt) {
							ans++;
						}
					} 
				}
			}
			cout << ans << '\n';
		} 
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Creeper::solve(); 
}
