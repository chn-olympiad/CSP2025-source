#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int n, a[N], nmax = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		nmax = max(nmax, a[i]);
	}
	if (n == 1 || n == 2) {
		cout << 0 << '\n';
		return 0;
	}
	if (n == 3) {
		int ans = 0;
		if (a[1] + a[2] + a[3] > nmax * 2)	ans++;
		cout << ans << '\n';
		return 0;
	}
	return 0;
}
