#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,P=998244353;
int n,a[N];
int fac[N],f[N],res[N],ans;
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}
int Cal(int n,int m){
	return (fac[n]/fac[m]/fac[n-m])%P;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=(fac[i-1]*i)%P;
	for(int i=1;i<=n;++i){
		int sum=qpow(2,i-1);
		ans=(ans+sum-res[a[i]]-1+P)%P;
		for(int j=5000;j>=a[i];--j){
			if(j==a[i])++f[j];
			else f[j]=(f[j]+f[j-a[i]])%P;
		}
		for(int j=1;j<=5000;++j)
			res[j]=(res[j-1]+f[j])%P;
	}
	printf("%lld\n",ans);
	return 0;
}
