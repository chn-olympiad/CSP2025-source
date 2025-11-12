#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,xR,r,c;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			xR=i;
			break;
		}
	}
	if(xR%n==0){
		c=xR/n;
		printf("%d ",xR/n);
	}else{
		c=xR/n+1;
		printf("%d ",xR/n+1);
	}
	if(c%2==1){
		if(xR%n!=0){
			printf("%d",xR%n);
		}else{
			printf("%d",n);
		}
	}else{
		if(xR%n!=0){
			printf("%d",n-xR%n+1);
		}else{
			printf("1");
		}
	}
	return 0;
}