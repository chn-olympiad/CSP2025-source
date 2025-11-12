#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10; 

int T, n, p1[N], p2[N], p3[N];

int max (int a, int b) {
	return a > b ? a : b;
}

int main () {
	freopen ("club.in", "r", stdin), freopen ("club.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	
	cin >> T;
	while (T--) {
		cin >> n;
		int sum1 = 0, sum2 = 0, sum3 = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a >= b and a >= c) p1[++sum1] = a - max (b, c);
			else if (b >= a and b >= c) p2[++sum2] = b - max (a, c);
			else if (c >= a and c >= b) p3[++sum3] = c - max (a, b);
			ans += max (a, max (b, c));
		} 
		if (sum1 > (n >> 1)) {
			sort (p1 + 1, p1 + 1 + sum1);
			for (int i = 1; i + (n >> 1) <= sum1; i++) ans -= p1[i];
		}
		if (sum2 > (n >> 1)) {
			sort (p2 + 1, p2 + 1 + sum2);
			for (int i = 1; i + (n >> 1) <= sum2; i++) ans -= p2[i];
		}
		if (sum3 > (n >> 1)) {
			sort (p3 + 1, p3 + 1 + sum3);
			for (int i = 1; i + (n >> 1) <= sum3; i++) ans -= p3[i];
		}
		cout << ans << endl;
	}
	
	return 0;
} 
