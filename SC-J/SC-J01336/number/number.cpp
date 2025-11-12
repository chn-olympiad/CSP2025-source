#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e6 + 5;
int a[10];

signed main () {
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);



	char x;
	while (cin >> x) {
		if (x >= '0' && x <= '9') {
			a[x - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] > 0) {
			for (int j = 1; j <= a[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}