#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 7;
ll sum[N];
ll n, k, d, ans, lt, ed = 1;
ll find_sum(ll rt) {
	for (int i = rt; i >= ed; --i) {
		if ((sum[i] ^ d) == k) return i;
	}
	return -1;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		ll x;
		scanf("%lld", &x); 
		d ^= x, sum[i] = (sum[i - 1] ^ lt);
		ll id = find_sum(i);
		if (id != -1) ed = i + 1, ++ans;
		lt = x;
	}
	cout << ans;
	return 0;
}

