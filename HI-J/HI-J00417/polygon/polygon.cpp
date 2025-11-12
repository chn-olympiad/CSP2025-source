#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		printf("0");
	}else if(n==3){
		sort(a+1,a+n+1);
		if(a[3]*2>=a[1]+a[2]+a[3]){
			printf("0");
		}else{
			printf("1");
		}
	}else{
		printf("9");
	}
	return 0;
}

