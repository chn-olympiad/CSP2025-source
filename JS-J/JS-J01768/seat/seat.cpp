#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, a[1005], R, ix;

void s() {
	for (int i = 1; i <= n * m; i++) {
		for (int j = i + 1; j <= n * m; j++) {
			if (a[i] < a[j])
				swap(a[i], a[j]);
		}
	}
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	R = a[1];
	s();
	for (ll i = 1; i <= n * m; i++) {
		if (a[i] == R) {
			ix = i;
			break;
		}
	}
	ll gr = (ix + n - 1) / n, mr = ix - (gr - 1) * n;
	if (gr % 2 == 0) {
		cout << gr << " " << n - mr + 1;
	} else {
		cout << gr << " " << mr;
	}
	return 0;
}
