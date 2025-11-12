#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int n, t[100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> (s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - '0'] += 1;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) {
			cout << i;
		}
	}
	cout << '\n';
	return 0;
}
