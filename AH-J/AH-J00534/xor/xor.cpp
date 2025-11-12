#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],h[500010],cnt,r=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		h[i]=h[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++)
		for(long long j=r;j<=i;j++)
			if((h[i]^h[j-1])==k){
				cnt++,r=i+1;
				break;
			}
	printf("%lld",cnt);
	return 0;
}
