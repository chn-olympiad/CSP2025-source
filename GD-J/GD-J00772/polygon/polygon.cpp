#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],f[10005],u,s,mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		s=(s+u)%mod;
		u=(u*2)%mod;
		for(int j=10000;j>=0;j--){
			if(j+a[i]>10000){
				u=(u+f[j])%mod;
				s=(s+f[j])%mod;
			}
			else{
				f[j+a[i]]=(f[j+a[i]]+f[j])%mod;
				if((j+a[i])>a[i]*2)s=(s+f[j])%mod;
			}
		}
	}
	printf("%lld",s);
	return 0;//zrt4
} 
