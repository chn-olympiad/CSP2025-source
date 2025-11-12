#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll n,k,a[N];

signed ll fun(ll l,ll r){
	ll sum=a[l];
	for(ll i=l+1;i<=r;i++) sum^=a[i];
	if(sum==k) return 1;
	return 0;
}

signed ll dfs(ll l,ll r){
	if(l>r) return 0;
	cout<<l<<" "<<r<<"\n";
	ll x=fun(l,r);
	ll maxn=max(maxn,x);
	if(l==r) return maxn;
	for(ll i=l;i<=r;i++){
		dfs(l,i);
		dfs(i+1,r);
	}
	return maxn;
}
/*
ll x=fun(l,mid)+fun(mid+1,r);
maxn=max(maxn,x);
*/

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	cout<<dfs(1,n);
	return 0;
}
/*
4 2
2 1 0 3
*/
/*
4 3
2 1 0 3
*/
/*
4 0
2 1 0 3
*/
