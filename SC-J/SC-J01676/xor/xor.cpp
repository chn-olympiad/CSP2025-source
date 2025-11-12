#include<bits/stdc++.h>
using namespace std;
const long long t=pow(2,31)-1+pow(2,31);
long long n,k,a[500005],flagr;
int ans;
long long xo(long long a,long long b){
	return (a&(t-b))|(b&(t-a));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	int r=1,l;
	for(;r<=n;r++){
		long long sum=0;
		for(l=r;l>=1;l--){
			if(flagr==l)break;
			sum=xo(sum,a[l]);
			if(sum==k){
				flagr=r;
				ans++;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}