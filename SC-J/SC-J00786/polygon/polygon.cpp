#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],p[N],m;
long long fact[N],finv[N],q[N],f[N][N],s[N][N],ans;
long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1ll)(res*=a)%=mod;
		(a*=a)%=mod;
		b>>=1;
	}
	return res;
}
long long C(int A,int B){
	if(A>B||B<0)return 0;
	return fact[B]*finv[A]%mod*finv[B-A]%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	fact[0]=finv[0]=1;
	for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;
	finv[n]=qpow(fact[n],mod-2);
	for(int i=n-1;i>=1;i--)finv[i]=(finv[i+1]*(i+1))%mod;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	m=1;
	int ls=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[ls])ls=i,m++;
		p[m]++;
	}
	unique(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		q[i]=(q[i-1]+p[i])%mod;
	}
	f[0][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<=p[i]&&a[i]*k<=j;k++){
				(f[i][j]+=C(k,p[i])*f[i-1][j-a[i]*k])%=mod;
			}
		}
	}
	for(int i=0;i<=m;i++){
		s[i][0]=1;
		for(int j=1;j<N;j++){
			s[i][j]=(s[i][j-1]+f[i][j])%mod;
		}
	}
	for(int i=1;i<=m;i++){
		for(int k=0;k<=p[i]-1;k++){
			(ans+=C(k,p[i]-1)*(qpow(2,q[i-1]+k)+mod-s[i-1][a[i]]+mod-k)%mod)%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
