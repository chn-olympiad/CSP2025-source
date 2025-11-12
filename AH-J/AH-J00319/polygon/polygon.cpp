#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long f[5005],a[5005];
long long ks(int x){
	long long a=1,u=2;
	while(x){
		if(x&1)a=a*u%mod;
		u=u*u%mod;
		x>>=1;
	}
	return a;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long m=a[1]+a[2];
	f[0]=1;
	for(int i=1;i<=2;i++){
		for(int j=m;j>=a[i];j--){
			f[j]+=f[j-a[i]];
		}
	}
	m=a[n];
	long long s=0;
	for(int i=3;i<=n;i++){
		s=(s+mod*2+ks(i-1)-1)%mod;
		for(int j=1;j<=a[i];j++){
			s=(s+mod*2-f[j])%mod;
		}
		for(int j=m;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	printf("%lld",s%mod);
	return 0;
}
