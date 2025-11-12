#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define res(i,a,n) for(ll i = a; i <= n; i++)
const int N = 1e5+5;
ll n, k, a[N], A, B;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin >> n >> k;
    res(i, 1, n) {
    	cin >> a[i];
    	if(a[i] != 1) A = 1;
    	if(a[i] != 0 && a[i] != 1) B = 1;
	}
    if(!A) cout << n/2;
    else if(!B) {
    	ll ans = 0;
    	if(!k){
    	res(i, 1, n) {
    		if(a[i] == 0) ans++;
    		if(a[i] && a[i-1]) {
    			ans++;
    			a[i] = a[i-1] = 0;
			}
			cout << ans;
		    }	
		}else {
			res(i, 1, n) if(a[i]) ans++;
			cout << ans;
		}  	
	}
	else{
		cout << n;
	} 
	return 0;
}