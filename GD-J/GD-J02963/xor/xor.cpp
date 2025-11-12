#include <bits/stdc++.h>
using namespace std;
const int maxn = (1e5) * 5;
int a[maxn + 5];
bool flags[maxn + 5] = {0};
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
	}
	int sum;
	int ans = 0;
	int xh = 0;
	for (int l = n ; l > 0; l--) {
		if (flags[l]) continue;
		
		for (int r = n; r >= l; r--) {
			if (flags[r]) continue;
			
			// ѡȡl -> r 
			
			sum = 0;
			for (int i = l; i <= r; i++) {
				if (flags[i]) {
					sum = -1;
					break;
				}
				if (i == l) sum = a[i];
				else sum ^= a[i];
			}
			
			if (sum == -1) continue;

			if (sum == k) {
				ans++;
				// cout << l << " -> " << r << "\n";
				for (int i = l; i <= r; i++) {
					flags[i] = 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
