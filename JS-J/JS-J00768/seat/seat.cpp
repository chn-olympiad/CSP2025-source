#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[1005];
ll x;
ll idx;
ll l,h;
ll qz(ll w){
	if(w%n==0){
		return w/n;
	}
	return w/n+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
	for(ll i = 1;i<=n*m;i++){
		if(a[i]==x){
			idx=i;
		}
	}
	l=qz(idx);
	if(l%2==1){
		h=idx-(l-1)*n;
	}else{
		h=n-(idx-(l-1)*n)+1;
	}
	cout<<l<<" "<<h;
	return 0;
}