#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],ans,mod=998244353;
void dfs(ll x,ll pos,ll maxa,ll num){
	if(x>=3&&num>2*maxa){
		ans++;
	}
	for(int i=pos+1;i<=n;i++){
		dfs(x+1,i,a[i],num+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans%mod;
	return 0;
}
