#include<bits/stdc++.h>
#define ll long long
using namespace std;
int len(int i){
	int mo = i%10;
	return (mo==0?(i==0?0:1):mo);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll ans,n,m;
	char cs[n+1] = {};
	cin >> n >> m;
	ll c[n+1] = {};
	cin >> cs;
	for(ll i=0;i<n;i++){
		cin >> c[i];
	}
	for(ll i=0;i<n;i++){
		if(cs[i]=='0'){
			continue;
		}
		if(c[i]<=0) continue;
		if(ans>=c[i]) continue;
		ans++;
	}
	cout << ans%998244353;
	return 0;
}
