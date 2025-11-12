#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node{
	int a;
	int num;
}b[100005];
int cmp(struct node v1,struct node v2){
	return v1.a>v2.a;
}
int main(){
	freopen("seat.in","r",stdin);
	//freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&b[i].a);
		b[i].num=i;
	}
	sort(b+1,b+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		//printf("%d ",b[i].a);
	}
	int c=0;
	for(int i=1;i<=n*m;i++){
		if(b[i].num==1){
			c=i;
		}
	}
	//printf("%d ",c);
	int ans1=ceil(c*1.0/n);
	printf("%d ",ans1);
	if(ans1%2==1){
		if(c%n==0){
			printf("%d",n);
		}else{
			printf("%d",c%n);
		}
	}else{
		if(c%n==0){
			printf("1");
		}else{
			printf("%d",n-c%n+1);
		}
	}
	return 0;
}