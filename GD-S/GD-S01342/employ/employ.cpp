#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;++i){
		ans*=n;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
} 
