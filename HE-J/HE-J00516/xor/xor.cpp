#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ll n,k,l,r;
	cin >> n >> k;
	ll a[n+1] = {},ans = 0;
	ll y[n+1] = {};
	ll lr[n][n] = {};
	for(ll i=0;i<n;i++){
		cin >> a[i];
		y[i]|=a[i];
		cout << y[i] << endl;
		if(a[i]<k) ans++;
	}
	if(ans==0) ans++;
	cout << ans << endl;
	return 0;
} 
