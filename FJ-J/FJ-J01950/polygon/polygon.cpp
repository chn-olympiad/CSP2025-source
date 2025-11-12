#include<bits/stdc++.h>
using namespace std;
long long const N=1e7+9;
long long n,a[N],ans=0,mod=998244353,v[N];
bool gz(long long x,long long y) {
	return x<y;
}
long long c(long long l,long long r) {
	long long t=1;
	for(long long i=l;i<=r;i++) {
		t*=i;
	}
	return t;
}
void dfs(long long x,long long k,long long m,long long l) {
	if(k>m*2) {
		ans++;
		for(long long i=1;i<l;i++) {
			ans+=c(l-i,l-1)/c(1,i);
			ans%=mod;
		}
		ans%=mod;
		return;
	}
	for(long long i=x; i>=1; i--) {
		if(v[i]==1) continue;
		v[i]=1;
		dfs(i,k+a[i],max(m,a[i]),min(i,l));
		v[i]=0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,gz);
	if(a[n]==1) {
		for(long long i=3;i<=n;i++) {
			ans+=c(n-i+1,n)/c(1,i);
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	dfs(n,0,0,1e9);
	cout<<ans%mod;
	return 0;
}