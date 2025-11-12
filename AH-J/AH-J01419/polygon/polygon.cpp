#include<iostream>
using namespace std;
const int Mod=998244353;
int n,a[5005];
bool b[5005];
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		ans=(ans+(1+n-i+1)*(n-i+1)/2)%Mod;
	}
	if(n<3){
		printf("%d",0);
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>a[1]&&a[1]+a[2]+a[3]>a[2]&&a[1]+a[2]+a[3]>a[2])
		    printf("%d",1);
		else printf("%d",0);
	}else printf("%lld",ans);
    return 0;
}
