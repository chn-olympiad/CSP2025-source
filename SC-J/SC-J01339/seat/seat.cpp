#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, x, a;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> x;
	ll len = n*m, p = 0;
	for (ll i = 1; i < len; i++) {
		cin >> a;
		if (a > x) {
			p++;
		}
	}
	ll chu = p / n, mu = p % n;
	if (chu % 2 == 0) {
		cout << chu + 1 << " " << mu + 1; 
	}
	else {
		cout << chu + 1 << " " << n - mu;
	}
	return 0;
} 