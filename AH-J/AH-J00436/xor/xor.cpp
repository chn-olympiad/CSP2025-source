#include<iostream>
#include<cstdio>

using namespace std;
using LL = long long;
const LL N = 5e5 + 5;

LL n,a[N],x[N],k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		x[i]=a[i]^x[i-1];
	}
	for(LL l=1;l<=n;l++)
		for(LL r=l;r<=n;r++){
			if((x[r]^x[l-1])==k)	cnt++;
		}
	printf("%lld",cnt);
	return 0;
}
