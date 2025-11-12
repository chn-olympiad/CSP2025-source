#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char c[N]; int n, t[100];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> (c + 1); n = strlen(c + 1);
	for (int i = 1; i <= n; i++) {
		if('0' <= c[i] && c[i] <= '9') t[c[i] - '0'] ++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= t[i]; j++) cout << i;
	}
	return 0;
}
