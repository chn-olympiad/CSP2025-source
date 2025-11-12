#include<bits/stdc++.h>
using namespace std;
int n,flag=1;
int a[5005];
const int Mod=998244353;
long long ans=0,sum=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]!=a[i-1]){
			flag=0;
		}
	}
	if(n<3){
		printf("0");
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			printf("1");
		}else{
			printf("0");
		}
	}
	if(flag==1){
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=n;j>n-i;j--){
				sum=sum*j%Mod;
			}
			for(int j=1;j<=i;j++){
				sum=sum/j;
			}
			ans=(ans+sum)%Mod;
		}
	}else{
		for(int i=3;i<=n;i++){
			sum=1;
			for(int j=n;j>n-i;j--){
				sum=sum*j%Mod;
			}
			for(int j=1;j<=i;j++){
				sum=sum/j;
			}
			ans=(ans+sum)%Mod;
		}
	}
	printf("%lld",ans);
	return 0;
}