#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> A,pjxor,dp;
ll pjor(ll l,ll r){
	return pjxor[r]^pjxor[l-1];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ll pjn,pjk;cin>>pjn>>pjk;
	A.resize(pjn+1),pjxor.resize(pjn+1),dp.resize(pjn+1);
	for(ll i=1;i<=pjn;i++){
		cin>>A[i];
		pjxor[i]=pjxor[i-1]^A[i];
	}
	for(ll i=1;i<=pjn;i++){
		dp[i]=dp[i-1];
		ll l=lower_bound(begin(dp),begin(dp)+i,dp[i])-begin(dp)+1;
		for(ll j=l;j<=i;j++){
			if(pjor(j,i)==pjk){
				dp[i]++;
				break;
			}
		}
	}
	cout<<dp[pjn];
	return 0;
} 
