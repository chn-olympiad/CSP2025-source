#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll M=998244353;
ll pja(ll pjn,ll pjm){
	ll sum=1;
	for(ll i=pjn;i>=pjn-pjm+1;i--){
		sum=(sum*i)%M; 
	}
	return sum;
}
ll pjc(ll pjn,ll pjm){
	return (pja(pjn,pjm)/pja(pjm,pjm))%M;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ll n;cin>>n;
	vector<ll> A(n+1);
	for(ll i=1;i<=n;i++){
		cin>>A[i];
	}
	if(n==3){
		ll ma=max({A[1],A[2],A[3]}),sum=A[1]+A[2]+A[3];
		cout<<(sum>ma*2?1:0);
	}
	else{
		ll ans=0;
		for(ll i=3;i<=n;i++){
			ans=(ans+pjc(n,i))%M;
		}
		cout<<ans;
	}
	return 0;
}
