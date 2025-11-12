#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],sum;
void dfs(ll j,ll ans,ll x){
	if(j>n) return;
	if(ans>=3&&x>a[j]*2){
		sum++;
		sum%=998244353;
	}
	for(ll i=j;i<=n;i++){
		dfs(i+1,ans+1,x+a[i+1]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0);
	cout<<sum%998244353;
	return 0;
}
