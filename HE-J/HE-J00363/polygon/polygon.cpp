#include <bits/stdc++.h>

using namespace std;
const int mod = 998244353;

int n;
int a[1000010];
int ans;

int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stsdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (n == 3) {
		int a1 = abs(a[1] - a[2]), a2 = abs(a[2] - a[3]), a3 = abs(a[1] - a[3]);
		int b1 = a[1] + a[2], b2 = a[2] + a[3], b3 = a[1] + a[3];
		if (a1 < a[3] && b1 > a[3] && a2 < a[1] && b2 > a[1] && a3 < a[2] && b3 > a[2]) cout << 1;
	}
	
	return 0;
}
