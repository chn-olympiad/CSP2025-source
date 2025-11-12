#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
string str;
map<int, int> mp;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			int _ = str[i] - '0';
			mp[_]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (mp[i] > 0) {
			cout << i;
			mp[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5

290es1q0
*/
