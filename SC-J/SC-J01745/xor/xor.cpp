#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N = 5e5+10;
ll n, k, a[N], kh;
bool A = 1, B = 1, C = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 225) {
			C = false;
			A = false;
			B = false;
		} else if (a[i] != 1 && a[i] != 0) {
			B = false;
			A = false;
		} else if (a[i] != 1) A = false;
	}
	if (A) {
		if (k == 1) {
			cout << n;
			return 0;
		}
		if (k == 0) {
			cout << n / 2;
			return 0;
		}
	} else if (B) {
		ll cnt = 0;
		if (k == 1) {
			for (ll i = 1; i <= n; i++) {
				if (a[i] == 1) cnt++;
			}
			cout << cnt;
			return 0;
		}
		if (k == 0) {
			for (ll i = 1; i <= n; i++) {
				if (a[i] == 0) cnt++;
				if (a[i] == 1 && a[i + 1] == 1 && i < n && i % 2 == 1) cnt++;
			}
			cout << cnt;
			return 0;
		}
	} else {
		ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			kh = 0;
			if (a[i] == k) {
				cnt++;
				continue;
			} else {
				for (ll j = 2; j <= n - i + 1; j++) {
					for (ll h = i; h <= j + i - 1; h++) {
						if (h == i) kh = a[h];
						else kh ^= a[h];
					}
					if (kh == k) {
						cnt++;
						i += j - 1;
						break;
					}
				}
			}
		}
		cout << cnt;
	}
	return 0;
}