#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 7, mod = 998244353;

LL n, l[N], a[N], tot;

void solve(){
	for(int i = 1; i <= n; ++i){
		LL maxn = l[i];
		for(int j = i; j <= n; ++j){
			LL p = a[j] - a[i-1];
			
			maxn = max(maxn, l[i]);
			
			if(p > maxn * 2){
				tot++;
				tot %= mod;
			}
		}
	}
	cout << tot % mod;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> l[i];
		a[i] = a[i-1] + l[i];
	}
	
	sort(l + 1, l + 1 + n);
	
	if(n <= 3){
		if(n < 3){
			cout << 0;
			return 0;
		}
		if(l[n] * 2 < l[1] + l[2] + l[3]){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	
	bool f = 1;
	for(int i = 1; i <= n; ++i){
		if(l[i] != 1){
			f = 0;
			break;	
		}
	}
	
	if(f){
		LL p = 0;
		for(int i = 1; i <= n - 2; ++i){
			p += i;
		}
		cout << p;
		return 0;
	}
	
	solve();
	return 0;
}
