#include<bits/stdc++.h>
const long long N=505,mod=998244353;
long long n,m,cnt,s[N],c[N],fact[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&s[i]);
	for(long long i=1;i<=n;i++)scanf("%lld",&c[i]),m+=c[i]==0;
	fact[0]=1;
	for(long long i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
	if(m==n)printf("%lld",fact[n]);
	else printf("0");
}