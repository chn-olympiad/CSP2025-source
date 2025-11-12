#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5001];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]+a[2]>a[2]*2){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	return 0;
}
