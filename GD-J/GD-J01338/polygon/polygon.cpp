#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,a[5005],f[25],sum[25],ans,y=1,jc[5005],ny[5005];
ll ksm(ll x,ll u){
	ll ans=1;
	while(u>1){
		if(u&1) ans=ans*x%mod;
		x=x*x%mod,u>>=1;
	}
	return ans;
}
void solve_in_2n(){
	for(ll i=1,now,z=0;i<(1<<(n));i++,z=0){
		now=i;
		for(ll j=n-1;j>=0;j--){
			if(now-(1<<j)>=0){
				f[++z]=a[j+1];
				sum[z]=sum[z-1]+f[z];
				now-=(1<<j);
			}
		}
		sort(f+1,f+1+z);
		if(f[z]*2<sum[z]&&z>2) ans++;
	}
	cout<<ans;
}
ll C(ll n,ll m){
	return jc[n]*ny[m]%mod*ny[n-m]%mod;
} 
void solve_in_al1(){
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	ny[n]=ksm(jc[n],mod-2)%mod;
	for(int i=n-1;i>0;i--) ny[i]=ny[i+1]*n%mod;
	for(int m=3;m<=n;m++){
		ans=(ans+C(n,m))%mod;
	}
	cout<<ans;
}
void solve_in_n2(){
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) y=0;
	}
	if(n<=20) solve_in_2n(); 
	else if(y==1) solve_in_al1();
	else solve_in_n2();
	return 0;
}
