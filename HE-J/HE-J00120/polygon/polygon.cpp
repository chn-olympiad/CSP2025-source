#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n;
int a[N];
int ans;
void sanb(int x, int y) {
	for(int i = y + 1;i <= n;i ++ ) {
		if(a[x] + a[y] + a[i] > 2 * max(a[i], max(a[x], a[y]))) ans ++ ;
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++ ) cin >> a[i];
	if(n < 3) {
		cout << 0;
		return 0;
	}
	for(int i = 1;i < n - 1;i ++ ) {
		for(int j = i + 1;j < n;j ++ ) {
			sanb(i, j);
		}
	}
	cout << ans;
	return 0;
}
