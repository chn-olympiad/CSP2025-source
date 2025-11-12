#include<bits/stdc++.h>
//O(2^n) or O(n)
//tot_get:64
#define MOD 998244353
using namespace std;
int a[5050];
int n;
long long anser=0;
void dfs(int dep,int tot,int mx/*,int ans,bool dk*/){
	if(dep>n) return (anser=(anser+((tot>2*mx)? 1 : 0))%MOD,void());
	dfs(dep+1,tot,mx);
	dfs(dep+1,tot+a[dep],max(mx,a[dep]));
}
int fast_power(int a,int b){
	unsigned long long tot=1;
	for(int i=1;i<=b;i++){
		tot=tot*a % MOD;
	}
	return tot;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f){
		unsigned long long k=fast_power(2,n);
		k-=((n*(n-1))/2+n+1)%MOD;
		cout<<k<<'\n';
	}
	else{
		dfs(1,0,0);
		cout<<anser<<'\n';
	}
	return 0;
}
