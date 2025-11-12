#include <bits/stdc++.h>
#define ll long long

using namespace std;

int const maxn = 5 * 1e5 + 10;
ll a[maxn];
ll xorh(ll l , ll r){
	ll x = a[l];
	for (int i = l + 1 ; i <= r ; i++){
		x ^= a[i];
	}
	return x;
}
int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	ll n , k , ans = 0;
	cin >> n >> k;
	for (ll i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	ll i = 1;
	for (ll j = 1 ; j <= n ; j++){
		if (xorh(i , j) == k){
			ans++;
			i = j + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
//fuck U CCF
