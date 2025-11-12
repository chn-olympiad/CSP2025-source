#include<iostream>
#include<cstdio>
int n,m,a[1500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int temp=a[1];
	for(int i=1;i<=n*m;i++){
		bool flag=true;
		for(int j=n*m;j>i;j--){
			if(a[j]>a[j-1]){
				int kkk=a[j];
				a[j]=a[j-1];
				a[j-1]=kkk;
			}
		}
	}
	int x=1,y=0,d=1;
	for(int i=1;i<=n*m;i++){
		//	printf("%d %d\n",a[i],i);
		y+=d;
		if(y>n){
			y=n,x++;
			d*=-1; 
		}
		if(y<=0){
			y=1,x++;
			d*=-1; 
		}
		if(a[i]==temp){
			printf("%d %d",x,y);
			return 0;
		}
	}
	return 0;
}
