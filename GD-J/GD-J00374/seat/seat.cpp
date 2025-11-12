#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++)
ll hang, lie;
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> hang >> lie;
	ll n = hang * lie;
	ll me, cnt = 1;
	cin >> me;
	rep(i, 2, n) {
		ll num;
		cin >> num;
		if(num > me) cnt++;
	}
	ll a = (cnt / hang) + 1, b =  cnt - (cnt / hang) * hang;
	if(b == 0) {
		a--;
		b = hang;
	}
	if(a % 2 == 0) {
		b = hang - b + 1;
	}
	cout << a << ' ' << b;
	return 0;
}
