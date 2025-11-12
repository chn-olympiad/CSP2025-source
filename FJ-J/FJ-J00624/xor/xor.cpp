#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],cnt,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			++cnt;
			sum=0;
		}else{
			sum^=a[i];
			if(sum==k){
				++cnt;
				sum=0;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}
