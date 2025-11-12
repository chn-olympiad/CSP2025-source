#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	unordered_map<int, int> mp;
	for (auto i : s) {
		if (i >= '0' && i <= '9') {
			mp[i - '0'] ++;
		}
	}
	
	for (int i = 9; i >= 0; i --) {
		while (mp[i] > 0) {
			cout << i;
			mp[i] --;
		}
	}
	
	return 0;
}
