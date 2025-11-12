#include<stdio.h>
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	scanf("%d %d\n%d",&n,&m,&a1);
	int x;
	int sum=1;
	for(int i=1;i<m*n;i++){
		scanf("%d",&x);
		sum+=(x>a1);
	}
	int c=(sum-1)/n+1,r;
	if(c&1)r=(sum-1)%n+1;
	else r=n-(sum-1)%n;
	printf("%d %d",c,r);
	return 0;
}
