#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,answer,a[500005];
void dfs(ll i,ll ans) {
	if(i>n) {
		if(ans>answer) {
			answer=ans;
		}
		return;
	}
	dfs(i+1,ans);
	ll x=0;
	for(ll j=i; j<=n; j++) {
		x^=a[j];
		if(x==k) {
			dfs(j+1,ans+1);
		}
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0);
	cout<<answer;
	return 0;
}