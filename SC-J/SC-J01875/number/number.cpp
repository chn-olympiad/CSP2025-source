#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long sum[10] = {0};
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum[s[i] - '0']++;
		}
	}
	string m = "";
	for (int i = 9; i >= 0; i--) {
		while (sum[i] != 0) {
			m += i + '0';
			sum[i]--;
		}
	}
	cout << m;
	return 0;
}