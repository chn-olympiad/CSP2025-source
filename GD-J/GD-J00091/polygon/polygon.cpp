#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) printf("1");
		else printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(sum[j]-sum[i-1]>a[j]*2) ans=(ans+1)%mod;
		}
	}
	printf("%d",ans);
	return 0;
}
