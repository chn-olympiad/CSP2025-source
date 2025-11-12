#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[500005]; 

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i] ^ a[i-1];
	}
	
	ll idx = 0, ans = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = idx; j < i; j++) {
			int k = a[j] ^ a[i];
			if (k == m) {
				ans++;
				idx = i;
				j = i;
			}
		}
	}
	cout << ans;
	return 0;
} 