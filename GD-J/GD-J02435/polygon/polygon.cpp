#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[5005],n,x;
long long ans,f[5005],s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;++i){
		ans=(ans+s[-~a[i]])%mod;
		f[5001]=(f[5001]*2)%mod;
		for(int j=5000;j>=0;--j){
			x=min(j+a[i],5001);
			f[x]=(f[x]+f[j])%mod;
			s[x]=(s[-~x]+f[x])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}
