#include <bits/stdc++.h>

using namespace std;

int num[14];
string c, ans;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	for(int i = 0; i < c.size(); i++) {
		if(c[i] >= '0' && c[i] <= '9') {
			num[c[i] - '0']++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		if(num[i] == 0) continue;
		for(int j = 1; j <= num[i]; j++) { ans += (i + '0'); }
	}
	cout << ans;
	
	return 0;
}
