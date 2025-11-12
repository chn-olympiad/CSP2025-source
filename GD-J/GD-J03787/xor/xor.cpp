#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], ans, mx, nxi;
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    ios::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) 
    	cin >> a[i];
	for (int l = 1; l <= n; l ++) {
		ans = 0, nxi = l;
		int sum = 0;
		for (int i = l; i <= n; ) {
			sum ^= a[i];
			i = max (i + 1, nxi);
			nxi = max (nxi, i);
			if (sum == k) {
				ans ++;
				sum = 0;
				nxi = i + 1;
			}
		}
		mx = max (mx, ans);
	}		
	cout << mx;
    return 0;
}

