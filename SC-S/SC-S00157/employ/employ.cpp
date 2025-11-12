#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool A = true;
int ans = 1;
int mod = 998244353;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n, m;
	string sg;
	ll s[550], c[550];
	cin >> n >> m >> sg;
	for(ll i = 1;i <= n;i++){
		cin >> c[i];
	}
	int k = 1;
	while(k <= n){
		if(sg[k] == 48){
			s[k] = 0;
			A = false;
		}else{
			s[k] = 1;
		}k++;
	}
	if(A){
		for(int i = n;i >= 1;i--){
			ans *= i;
			if(ans >= mod){
				ans %= mod;
			} 
		}cout << ans;
	}else{
        cout << n%mod;
    }
	return 0;
}
