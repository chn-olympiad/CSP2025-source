#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll const Maxn = 5000 + 10;
ll a[Maxn];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	ll n , ans = 0;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	if (n == 3){
		cout << 1 << endl;
		return 0; 
	} 
	for (ll i = 1 ; i <= n ; i++){
		for (ll j = i + 2 ; j <= n ; j++){
			ll maxn = -114514 , he = 0;
			for (ll x = i ; x <= j ; x++){
				he += a[x];
				if (maxn <= a[x]){
					maxn = a[x];
				}
			}
			if (he > maxn * 2){
				ans++;
				cout << ' ' << i << ' ' << j << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
//CCF nmsl
