#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[(int)5e5 + 10];
int pre[(int)5e5 + 10];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	pre[1] = a[1];
	for (int i = 2; i <= n; i ++) {
		pre[i] = a[i] ^ pre[i - 1];
	}
	
	int tmp, lst = 1, ans = 0;
	for (int r = 1; r <= n; r ++) {
		for (int l = r; l >= lst; l --) {
			if (l == 1) tmp = pre[r];
			else tmp = pre[r] ^ pre[l - 1];
			if (tmp == k) {
				lst = r + 1;
				ans ++;
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
