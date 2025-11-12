#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,M=998244353;
int n,a[N],fac[N],lf[N];
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
}
void init(){
	fac[0]=1;// 0! = 1
	for(int i=1;i*2<=n+4;i++) {
		fac[i]=fac[i-1]*i;
		if(fac[i]>M) fac[i]=fac[i]%M;
	}
	lf[0]=1;
	for(int i=1;i*2<=n+4;i++) {
		lf[i]=lf[i-1]*(n-i+1);
		if(lf[i]>M) lf[i]=lf[i]%M;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()){
		init();
		int ans=1,la=1;
		for(int i=3;i<=n;i++){
			if(i<=n/2) ans*=fac[i];
			else ans*=fac[n-i+1];
			if(i<=n/2) la*=lf[i];
			else la*=lf[n-i+1];
			if(ans%la==0) ans=ans/la,la=1;
		}
		cout<<ans/la;
	}
	return 0;
}

