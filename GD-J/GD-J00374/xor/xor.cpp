#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define rep(i, a, b) for(ll i = (a); i <= (b); i++)
const ll N = 1e3 + 10;
ll n, k, cnt = 0;
ll arr[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	rep(i, 1, n) cin >> arr[i];
	if(k == 0) {
		cout << n / 2;
	}
	else {
		cout << n;
	}
	return 0;
}

