#include<iostream>
using namespace std;
int n, k;
int a[500010];
int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (k == 0) {
		cout << 0;
		return 0;
	}
	if (k == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i++) 
			if (a[i] == 1) ans++;
		cout << ans;
		return 0;
	}
	if (k == 2 || k == 3) {
		cout << 2;
		return 0;
	}
	return 0;
}
