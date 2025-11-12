#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5010],ans=0;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) printf("1");
		else printf("0");
		return 0;
	}
	else if(a[n]==1 && a[1]==1){
		if(n==3) printf("1");
		else if(n==4) printf("5");
		else{
			int add=((n*(n-1))/2)%mod;
			ans=(1+n)%mod;
			for(int i=n-1;i>n/2;i--){
				ans=((ans%mod)+(add%mod)*2)%mod;
				if(i!=4) add=((add%mod)*(i-1))%mod;
			}
			printf("%d",ans%mod);
		}
		return 0;
	}
	return 0;
} 
