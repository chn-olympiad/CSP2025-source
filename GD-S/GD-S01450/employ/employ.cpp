#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n, m, a[505], ans = 1;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
//	cout << s; 
	for(ll i = 0; i < n; i++){
		ll kiopiop;
		cin >> kiopiop;
		a[kiopiop]++; 
	}
	bool kop = true;
	for(ll i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			kop = false;
			break;
		}
	}
	if(kop == true){
		for(ll i = 0; i < m; i++){
			ans*=n;
			ans%=mod;
			n--;
		}
		cout << ans;
	}
	else{
		cout << 0;
	}
	return 0;
}
