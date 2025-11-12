#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=5010;
const ll mod=998244353;
ll ans=0;
int n;
int a[N];
int maxn,sumn;
void dfs(int pos,int maxv,int sum,int res) {
	if(pos==n+1) {
		if(sum>maxv*2&res>=3) ans=(ans+1)%mod;
		return ;
	}
	dfs(pos+1,maxv,sum,res);
	dfs(pos+1,max(maxv,a[pos]),sum+a[pos],res+1);
}
ll qpow(ll x,ll y) {
	ll res=1;
	while(y) {
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y/=2;
	}
	return res;
} 
ll inv[N],frc[N];
ll C(int n,int m) {
	if(n>m) return 0;
	if(!n) return 1;
	if(n==m) return 1;
	return frc[m]*inv[n]%mod*inv[m-n]%mod;
} 
int main() {
//	double bgn=clock();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=20) {
		dfs(1,0,0,0);
		cout<<ans;
		return Suika;
	}
	for(int i=1; i<=n; i++) maxn=max(maxn,a[i]);
	frc[0]=1;
	int k=0;
	for(int i=1; i<=n; i++) {
		k+=a[i];
		frc[i]=frc[i-1]*i%mod;
	}
	inv[n]=qpow(frc[n],mod-2);
	for(int i=n-1; i>=1; i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=3; i<=n; i++) ans=(ans+C(i,n))%mod;
	for(int i=0; i<=min(2,k); i++) {
		ll res=0;
		for(int j=3-i; j<=n-k; j++) res=(res+C(j,n-k))%mod;
		ans=(ans-C(i,k)*res%mod+mod)%mod;
	}
	cout<<ans;
//	double ed=clock();
//	cout<<"\n"<<(ed-bgn)*1000/CLOCKS_PER_SEC;
	return Suika;
}