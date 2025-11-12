#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

ll n, k, a[500005], fenjie[25][500005], fenjiek[25];


bool flagA = true, flagB = true;

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1) flagA = false; 
		if (a[i] != 1 && a[i] != 0) flagB = false;
	}
	
	if (flagA) {
		cout << n / 2;
		return 0;
	} else if (flagB) {
		ll ans = 0;
		if (k == 1) {
			for (int i = 1; i <= n; i ++) {
				ans += a[i];
			}
		} else {
			for (int i = 1; i <= n; i ++) {
				if (a[i] == 0) ans ++;
				else if (a[i] == 1 && a[i+1] == 1) {
					ans ++;
					i ++;
				} 
			}
		}
		cout << ans;
		return 0;
	} else {
		
	}
	return 0;
}
