#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a[10] = {0};
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			int t = s[i] - '0';
			a[t]++;
		}
	}
	if (a[9] == 0 && a[8] == 0 &&a[7] == 0 &&a[6] == 0 &&a[5] == 0 &&a[4] == 0 &&a[3] == 0 &&a[2] == 0 &&a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}