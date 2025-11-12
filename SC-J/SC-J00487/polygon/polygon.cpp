#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",strin);
	freopen("polygon.out","w",strout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		printf("0");
	}
	if(n==3){
		if(max(a[1],a[2],a[3])*2<a[1]+a[2]+a[3]){
			printf("1");
		}
	}
	return 0;
}