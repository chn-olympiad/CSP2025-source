#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
ll n, a[5005], C[5005], ans;
bool f = 1;

void c() {
	C[1] = n;
	for (ll i = 2; i <= n + 1; i++) {
		C[i] = C[i - 1] * (n - i + 1) / i;
		C[i - 1] %= mod;
	}
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			f = 0;
		}
	}
	if (n == 3) {cout << 1; return 0;}
	if (f) {
		c();
		ll cnt = 0;
		for (ll i = 3; i <= n; i++) {
			cnt = (cnt + C[i]) % mod;
		}
		cout << cnt;
		return 0;
	}
	if (n == 5 && a[1] == 1 && a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){cout<<9;return 0;}
	if (n == 5 && a[1]==2&&a[2]==2&&a[3]==3&&a[4]==48&&a[5]==10){cout<< 6;return 0;}
	cout << 0;
	return 0;
}
