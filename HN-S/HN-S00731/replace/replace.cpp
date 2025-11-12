#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;
string s[N][2];
map<string, string>mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s[i][0] >> s[i][1];
		mp[s[i][0]] = s[i][1];
	}
	while(q--){
		string t1t, t2t;cin >> t1t >> t2t;
		if(mp.find(t1t) != mp.end() && mp[t1t] == t2t){
			cout << 1 << "\n";
		}else cout << 0 << "\n";
	}
	return 0;
}
