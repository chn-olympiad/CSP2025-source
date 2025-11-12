#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int a[5010];
long long fac[5010];
long double inv[5010];
long long c(int n,int m) {
	return fac[m]*inv[n]*inv[m-n];
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	fac[0]=1;
	for(int i=1; i<=5000; i++) {
		fac[i]=fac[i-1]*i;
	}
	inv[0]=inv[1]=1;
	for(int i=2; i<=5000; i++) {
		inv[i]=inv[i-1]/double(i);
	}
	int n;
	cin>>n;
	int maxx=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	long long ans=0;
	if(maxx==1) {
		for(int i=3; i<=n; i++) {
			ans=(ans+c(i,n)%mod)%mod;
		}
		cout<<ans;
	} else if(n==3) {
		if(a[0]+a[1]+a[2]>2*max({a[0],a[1],a[2]})) {
			ans++;
		}
		cout<<ans;
	} else if(n==4) {
		if(a[0]+a[1]+a[2]>2*max({a[0],a[1],a[2]})) {
			ans++;
		}
		if(a[0]+a[1]+a[3]>2*max({a[0],a[1],a[3]})) {
			ans++;
		}
		if(a[0]+a[3]+a[2]>2*max({a[0],a[3],a[2]})) {
			ans++;
		}
		if(a[3]+a[1]+a[2]>2*max({a[3],a[1],a[2]})) {
			ans++;
		}
		if(a[0]+a[1]+a[2]+a[3]>2*max({a[0],a[1],a[2],a[3]})) {
			ans++;
		}
		cout<<ans;
	} else if(n==5) {
		if(a[0]+a[1]+a[2]>2*max({a[0],a[1],a[2]})) {
			ans++;
		}
		if(a[0]+a[1]+a[3]>2*max({a[0],a[1],a[3]})) {
			ans++;
		}
		if(a[0]+a[1]+a[4]>2*max({a[0],a[1],a[4]})) {
			ans++;
		}
		if(a[3]+a[1]+a[4]>2*max({a[3],a[1],a[4]})) {
			ans++;
		}
		if(a[0]+a[3]+a[2]>2*max({a[0],a[3],a[2]})) {
			ans++;
		}
		if(a[0]+a[2]+a[4]>2*max({a[0],a[2],a[4]})) {
			ans++;
		}
		if(a[0]+a[4]+a[3]>2*max({a[0],a[4],a[3]})) {
			ans++;
		}
		if(a[3]+a[1]+a[2]>2*max({a[3],a[1],a[2]})) {
			ans++;
		}
		if(a[4]+a[1]+a[2]>2*max({a[4],a[1],a[2]})) {
			ans++;
		}
		if(a[4]+a[3]+a[2]>2*max({a[4],a[3],a[2]})) {
			ans++;
		}
		if(a[0]+a[1]+a[2]+a[3]>2*max({a[0],a[1],a[2],a[3]})) {
			ans++;
		}
		if(a[0]+a[1]+a[2]+a[4]>2*max({a[0],a[1],a[2],a[4]})) {
			ans++;
		}
		if(a[0]+a[1]+a[4]+a[3]>2*max({a[0],a[1],a[4],a[3]})) {
			ans++;
		}
		if(a[0]+a[4]+a[2]+a[3]>2*max({a[0],a[4],a[2],a[3]})) {
			ans++;
		}
		if(a[4]+a[1]+a[2]+a[3]>2*max({a[4],a[1],a[2],a[3]})) {
			ans++;
		}
		if(a[0]+a[1]+a[2]+a[3]+a[4]>2*max({a[0],a[1],a[2],a[3],a[4]})) {
			ans++;
		}
		cout<<ans;
	}
	return 0;
}
