#include <bits/stdc++.h>
using namespace std;
const int N=5005,M=5e4+5;
const long long mod=998244353;
int a[N];
long long v[M],fac[N];
long long inv(long long x) {
	long long res=1,y=mod-2;
	while (y) {
		if (y&1) {
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int flag=1;
	fac[0]=1;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i]!=1) {
			flag=0;
		}
		fac[i]=fac[i-1]*i%mod;
	}
	if (flag==1) {
		long long res=0;
		for (int i=3;i<=n;i++) {
			res=(res+fac[n]*inv(fac[n-i])%mod*inv(fac[i])%mod)%mod;
		}
		printf("%lld",res);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+1+n);
	v[0]=1;
	long long ans=0;
	for (int i=1;i<n;i++) {
		for (int j=50000-a[i];j>=0;j--) {
			v[j+a[i]]=(v[j+a[i]]+v[j])%mod;
		}
		for (int j=a[i+1]+1;j<=50000;j++) {
			ans=(ans+v[j])%mod;
		}
	} 
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
