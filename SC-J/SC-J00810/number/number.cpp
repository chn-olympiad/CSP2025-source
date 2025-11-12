#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int cnt[11];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int k = 1; k <= cnt[i]; k++) {
			cout << i;
		}
	}
	return 0;
}