#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e7 + 5;
int a[maxn];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n * m; ++i){
		cin >> a[i];
	}
	ll x = a[1];
	sort(a + 1, a + n*m + 1);
	ll d = 0;
	for(ll i = n * m; i >= 1; i--){
		d++;
		if(a[i] == x){
			break;
		}
	}
	ll l = d / n;
	if(d % n != 0) l++;
	ll r;
	if(l % 2 == 0){
		int cnt = d % n;
		r = n + 1 - cnt;
		if(cnt == 0){
			r = 1;
		}
	}
	if(l % 2 == 1){
		ll cnt = d % n;
		r = cnt;
		if(cnt == 0){
			r = n;
		}
	}
	cout << l << " " << r;
	return 0;
}
