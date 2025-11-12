#include<bits/stdc++.h>
using namespace std;
using ll = long long; 
ll num[500100];
ll n;
ll k;
bool check(ll l,ll r){
	if((num[r]^num[l-1])==k)return 1;
	return 0;
}
ll dp[500100];
ll dfs(ll a){
	if(a>n)return 0;
	if(dp[a])return dp[a];
	//ѡ
	ll i;
	for(i = a; i <= n; i ++){
		if(check(a,i))break;
	}
	if(i<=n)dp[a]=max(dfs(a+1),dfs(i+1)+1);
	else dp[a]=dfs(a+1);
	return dp[a];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i = 1; i <= n; i ++) {
		ll x;
		cin>>x;
		num[i]=(num[i-1]^x);
	}
	cout<<dfs(1);
	return 0;
} 
