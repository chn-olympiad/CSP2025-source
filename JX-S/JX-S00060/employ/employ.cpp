#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,mod=998244353,ans;
string s;
ll c[505];
ll dfs(ll x){
	ll num=1;
	for(ll i=2;i<=x;i++){
		num=(num*i)%mod;
	}
	return num%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll nn=n;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) nn--;
	}
	if(nn<m){
		cout<<0;
		return 0;
	}
	for(ll i=m;i<=n;i++){
		ll t=(dfs(n)/dfs(n-i))%mod;
		ans=(ans+t)%mod;
	}
	cout<<ans%mod;
	return 0;
}

