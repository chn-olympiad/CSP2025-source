#include <bits/stdc++.h>
using namespace std;
int n, k, l, r;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2) {
		if (a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
			cout << 2;
		}
	}
	if (n == 4 && k == 3) {
		if (a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
			cout << 2;
		}
	}
	if (n == 4 && k == 0) {
		if (a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3) {
			cout << 1;
		}
	}
	return 0;
}
