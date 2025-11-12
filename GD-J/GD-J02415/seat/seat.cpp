#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 0;
ll m = 0;
ll cnt = 0;
ll fi = 1;
ll s[1000100] = {0};
ll mp[150][150] = {0};

bool cmp (ll x, ll y) {
	return x > y;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> s[i];
		if (i == 1) {
			cnt = s[i];
		}
	}
	sort(s + 1, s + n * m + 1, cmp);
	for (ll i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (ll j = 1; j <= n; j++) {
				mp[j][i] = s[fi];
				if (s[fi] == cnt) {
					cout << i << " " << j << '\n';
					return 0;
				}
				fi += 1;
			}
		}
		else {
			for (ll j = n; j >= 1; j--) {
				mp[j][i] = s[fi];
				if (s[fi] == cnt) {
					cout << i << " " << j << '\n';
					return 0;
				}
				fi += 1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
