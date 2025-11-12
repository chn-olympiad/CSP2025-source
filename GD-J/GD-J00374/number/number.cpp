#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++) 
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<char> v;
	rep(i, 0, s.size()) {
		if(s[i] >= '0' && s[i] <= '9') v.push_back(s[i]);
	}
	sort(v.begin(), v.end(), greater<>());
	bool flag = 0;
	for(auto e : v) {
		if(e != '0') flag = 1;
		if(flag == 1) cout << e;
	}
	if(flag == 0) cout << 0;
	return 0;
}
