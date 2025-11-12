#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
bool A = 1,B = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin >> n >> k;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1){
			A = 0;
		}
		if(!(a[i] >= 0 && a[i] <= 1)){
			B = 0;
		}
	}
	if(A){
		cout << n / 2;
		return 0;
	}
	ll ans = 0;
	if(B){
		if(k == 0){
			for(ll i = 1;i <= n;i++){
				if(a[i] == 0){
					ans++;
				}else if(a[i] == a[i - 1]){
					ans++;
					a[i] = 0;
				}
			}
			cout << ans;
		}else{
			for(ll i = 1;i <= n;i++){
				if(a[i] == 1){
					ans++;
				}
			}
			cout << ans;
		}
		return 0;
	}
	for(ll i = 1;i <= n;i++){
		if(a[i] == k){
			ans++;
		}
	}
	cout << ans;
}
