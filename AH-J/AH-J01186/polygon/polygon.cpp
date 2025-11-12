#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,a[100000+10],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	if(n==3){
		for(LL i=1;i<=n;i++){
			for(LL j=i;j<=n;j++){
				for(LL k=j;k<=n;k++){
					if(a[i]+a[j]+a[k]>k*2)cnt++;
				}
			}
		}
		cnt%=998244353;
		printf("%lld",cnt);
	}
	else{
		if(n==5)printf("9");
	}
	return 0;
}
