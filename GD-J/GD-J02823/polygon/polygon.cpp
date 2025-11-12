#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=m;++i)
#define ref(i,n,m) for(int i(n);i>=m;--i)
#define ll long long
using namespace std;
const int mod=998244353;
int a[5005],n;
ll inv[5005],frac[5005];
ll ans,f[105][105][105];
bitset<105> mp[105][105];
bool check(){
	rep(i,1,n) if(a[i]!=1) return 0;
	return 1;
}
int Pow(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int dg(int d,int s,int p){
	if(mp[d][s][p+100]) return f[d][s][p+100];
	if(s<0) return 0;
	if(d==0&&s>=0&&p<=0) return 1;
	if(d==0) return 0;
	f[d-1][s][p+100]=dg(d-1,s,p);
	f[d-1][s-a[d]][p+100-1]=dg(d-1,s-a[d],p-1);
	return f[d][s][p+100]=(f[d-1][s][p+100]+f[d-1][s-a[d]][p+100-1])%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	rep(i,1,n) cin>>a[i];
	frac[0]=1;
	rep(i,1,n) frac[i]=frac[i-1]*i%mod;
	inv[n]=Pow(frac[n],mod-2);
	ref(i,n-1,1) inv[i]=inv[i+1]*(i+1)%mod;
	rep(i,3,n){
//		cout<<frac[i]<<" "<<inv[i]<<"\n";
		ans=(ans+frac[n]*inv[n-i]%mod*inv[i]%mod)%mod;
	}
	if(check()){
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	rep(i,3,n){
		ans=(ans-dg(i-1,a[i],2)+mod)%mod;
//		cout<<dg(i-1,a[i],2)<<"\n";
	}
	cout<<ans+1;
	return 0;
}
