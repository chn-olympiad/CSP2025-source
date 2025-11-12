#include<bits/stdc++.h>
using namespace std;
int a[109*109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d\n", &n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d", &a[i]);
	}
	int p=a[1],ret=0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			ret=n*m-i+1;
			break;
		}
	}
//	for(int i=n*m;i>=1;i--){
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	printf("%d\n", ret);
	
	int c=(ret-1)/n+1;
	
	int r1=ret-(c-1)*n,r=0;
//	printf("%d\n", r1);
	if(c%2==1){
		r=r1;
	}else{
		r=n-r1+1;
	}
	printf("%d %d", c,r);
	return 0;
}