#include<bits/stdc++.h>
using namespace std;
string s;
int n[11];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = n[i]; j > 0; j--) {
			cout << i;
		}
	}
	return 0;
}