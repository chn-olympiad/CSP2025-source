#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//nÐÐmÁÐ 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ll n,m;
	cin>>n>>m;
	ll k=1;
	ll a;
	cin>>a;
	for(ll i = 0; i+1 < n*m; i ++){
		ll x;
		cin>>x;
		if(x>a)k++;
	}
	ll b = ceil(1.0*k/n);
	ll c = (k-1)%n+1;
	if(b%2==0)c=m-c+1;
	cout<<b<<' '<<c;
	return 0;
} 
