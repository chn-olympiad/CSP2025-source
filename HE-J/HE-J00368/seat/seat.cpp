#include<bits/stdc++.h>
int n,m,a[1001];
int ans[20][20];
int lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n*m;i++){
		scanf("%d",&a[i]);
	}
	int scr=a[1];
	for(int i = 1;i <= n * m;i++){
		for(int j = i+1 ;  j<= n*m;j++){
			if(a[i]<a[j]) {
				int t = a[i];
				a[i]=a[j];
				a[j]=t;

			}
		}
	}
////	for(int i = 1;i <= n*n;i++){
////		printf("%d\n",a[i]);
////	}
	int rw;
	for(int i = 1;i <= n*m;i++){
		if(a[i]==scr){
			rw=i;
			break;
		}
	}
////	printf("weizhi:%d\n",rw);
	int r = rw;
////	printf("weizhi2:%d",r);
////	printf("%d\n",r/n+1);
////	if (r/n==0){
////		if(r/n%2==1){
////			printf("%d %d\n",r/n,n);
////		}else{
////			printf("%d 1\n",r/n);
////		}
////	}else{
////		printf("%d ",r/n+1);
////		if(r/n+1%2==1){
////			printf("%d\n",r%n);
////		}else{
////			printf("%d\n",n-r%n+1);
////		}
////	}
	//printf("%d\n",r/n);
	if(r % n == 0){
		lie = r/n,hang;
		if(lie%2==0){
			hang = 1;
			//printf("o");
		}else{
			hang = n;
		}
		printf("%d %d\n",lie,hang);
	}else{
		lie = r/n+1,hang;
		if(lie % 2 == 0){
			hang = n-r%n+1;
		}else{
			hang = r%n;
		}
		printf("%d %d\n",lie,hang);
	}


	return 0;
}
