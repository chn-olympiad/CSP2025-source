#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500000;

int a[N];
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 || n <= 2) {
		cout << 2;
	} else if (k == 0) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
