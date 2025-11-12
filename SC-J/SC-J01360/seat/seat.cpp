#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 17;
ll R;
ll n, m;
ll a[N * N];
ll b[N][N];

bool cmp(ll u, ll v) {
	return u > v;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for (ll i = 1; i <= n * m; ++i) {
		cin >> a[i];
		if (i == 1) {
			R = a[i];
		}
	}
	
	sort(a + 1, a + n * m + 1, cmp);
	ll la = 0;
	
	for (ll i = 1; i <= m; ++i) {
		if (i & 1) {
			for (ll j = 1; j <= n; ++j) {
				b[i][j] = a[++la];
				if (b[i][j] == R) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		} else {
			for (ll j = n; j >= 1; --j) {
				b[i][j] = a[++la];
				if (b[i][j] == R) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	
	return 0;
}