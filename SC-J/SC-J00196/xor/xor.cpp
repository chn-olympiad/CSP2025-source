#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, a[500005], ans = 0;
bool A = true, B = true,C = true;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == k){
			ans++;
		}if(a[i] != 1){
			A = false;
		}if(a[i] != 1 && a[i] != 0){
			B = false;
		}if(a[i] > 255){
			C = false;
		}
	}if(k == 0 && A){
		cout << 0;
	}else if(k <= 1 && B){
		cout << ans;
	}
	return 0;
}
