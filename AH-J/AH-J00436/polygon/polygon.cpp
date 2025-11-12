#include<iostream>
#include<cstdio>

using namespace std;
using LL = long long;
const LL N = 5e3 + 5,mod=998244353;

LL n,h[N],cnt,js;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	scanf("%lld",&n);
	if(n<3){
		printf("0");
		return 0;
	}
	for(LL i=1;i<=n;i++)	{
		scanf("%lld",h+i);
		if(h[i]==1)	js++;
	}
	if(js==n){
		LL sum=0;
		for(LL i=n;i>=1;i--){
			sum+=i;
			sum%=mod;
		}
		printf("%lld",sum%mod);
		return 0;
	}
	for(LL l=1;l<=n;l++){
		for(LL m=1;m<=n-l;m++){
			LL r=l+m,maxn=0,sum=0;
			for(LL i=l;i<=r;i++){
				maxn=max(maxn,h[i]);
				sum+=h[i];
			}
			if(sum>maxn*2)	cnt++;
			cnt%=mod;
		}
	}
	printf("%lld",cnt%mod);
	return 0;
}
