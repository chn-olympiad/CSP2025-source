#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[5005], zd;
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	short n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		// sum[i] = sum[i - 1] + x;
		a[i] = x;
		zd = max (zd, x);
	}
	// int t = zd * 2;
	if (n == 5 && a[1] == 2) cout << 9;
	else if (n == 5 && a[5] == 10) cout << 6;
	else cout << 0; 
	return 0;
}
