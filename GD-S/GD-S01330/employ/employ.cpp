#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll Mod = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n; cin >> n;
	ll p = 1;
	for (ll i = 1; i <= n; i ++ )
		p = (p * i) % Mod;
	cout << p << '\n';
	return 0;
} 
