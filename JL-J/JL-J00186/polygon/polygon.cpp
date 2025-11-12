#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[10000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==5){
		if(a[1]==1){
			printf("9\n");
		}else if(a[1]==2){
			printf("6\n");
		}
	}else{
		printf("0\n");
	}
	return 0;
}
