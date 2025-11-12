#include <bits/stdc++.h>
using namespace std;

int main () {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	map<string, string> mp;
	cin >> n >> q;
	for (int i = 1;i <= n;i++) {
		string s, t;
		cin >> s >> t;
		mp[s] = t;
	}
	for (int i = 1;i <= q;i++) {
		int ans = 0;
		string a, b, tmp1 = "", tmp2 = "";
		cin >> a >> b;
		if(mp[a] == b) ans++;
		vector<string> g, vg;
		for (int j = 0; j < a.size();j++) {
			if(a[i] != b[i]) {
				tmp1 = tmp1 + a[i];
				tmp2 = tmp2 + b[i];
			}
		}
		if(mp[tmp1] == tmp2) ans++;
		cout << ans << endl;
	}
	
	return 0;
}
