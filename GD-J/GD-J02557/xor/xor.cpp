#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int c[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int ans = 0, res = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 1) ans++; 
		if (c[i] == 0) res++;
	} if (k == 0) {
		cout << ans / 2 + res << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
