#include<stdio.h>
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={0},copy,R;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		int j;
		scanf("%d",&j);
		if(i==1)R=j;
		a[0]++;
		for(int f=1;f<=a[0];f++){
			if(j>a[f]){
				copy=a[f];
				a[f]=j;
				j=copy;
			}
		}
	}
	int x,y;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			if(i%n==0){
				x=i/n;
			}else{
				x=i/n+1;
			}			
			if(x%2==0){
				y=n-i%n+1;
				if(i%n==0)y=1;
			}else{
				y=i%n;
				if(y==0)y=n;
			}
			printf("%d %d",x,y);
			break;
		}
	}
	return 0;
}