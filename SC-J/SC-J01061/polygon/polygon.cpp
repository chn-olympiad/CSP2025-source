#include <bits/stdc++.h>
using namespace std;
int a[5005]; 
long long x=0,o=0;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		o+=a[i];
	}
	int o1=o;
	sort(a+1,a+n+1);
	if(n<3){
		printf("0");
		return 0;
	}
	if(n=3){
		if(a[1]+a[2]>a[3]){
			printf("1");
		}
		else{
			printf("0");
		}
		return 0;
	}
	if(n>3 && n<500){
		for(int i=n;i>3;i--){
			if(o-a[i]<a[i]){
				printf("%lld",&x);
				return 0;
			} 
			if(a[i]==a[i-1]){
				x+=(i-2)*i;
			}
		}
	}
	if(n>500){
		x=n*(n-1);
	}
	x=x%998244353;
	printf("%lld",x);
	return 0;
}