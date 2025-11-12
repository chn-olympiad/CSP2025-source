#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e7 + 5;
int a[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k;
	cin >> n >> k;
	ll x = 1;
	for(ll i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] == 1 && x == 1) x = 1;
		else x = 0;
	}
	if(x == 1 && k == 0){
		cout << n / 2;
	}
	if(x == 0 && k == 0){
		int y1 = 0, y2 = 0;
		for(ll i = 1; i <= n; ++i){
			if(a[i] == 1) y1++;
			if(a[i] == 0) y2++;
		}
		cout << y1 / 2 + y2;
	}
	if(x == 0 && k == 1){
		int y1 = 0, y2 = 0;
		for(ll i = 1; i <= n; ++i){
			if(a[i] == 1) y1++;
			if(a[i] == 0) y2++;
		}
		cout << y1;
	}
	return 0;
}
