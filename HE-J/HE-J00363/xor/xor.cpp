#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;

int n, k;
int ans, a[N];

int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		ans += a[i];
	}
	if (ans >= n / 2) {cout << ans; return 0;}
	
	if (n == 1) {
		if (a[1] != k) cout << 0;
		else cout << 1;
	}
	if (n == 2) {
		ans = 0;
		if (a[1] == k) ans ++;
		if (a[2] == k) ans ++;
		if ((a[1] xor a[2]) == k) ans ++;
		cout << ans;
	}
	
	if (ans == n) {
		int cnt = 2;
		while (cnt <= n) {
			for (int i = n; i >= 1; i --) {
				if (i < cnt) continue;
				ans ++; 
			}
			cnt *= 2;
		}	
	}
	cout << ans << '\n';
	
	
	return 0;
}
/*
3 0
1 1 1
100 1
0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
