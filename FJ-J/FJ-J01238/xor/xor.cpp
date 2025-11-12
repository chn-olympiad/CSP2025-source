#include<stdio.h>
int n,key,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",n,key);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int max=0;
	for(int i=1;i<=n;i++){
		int ant=0,sum=a[i];
		for(int j=i+1;j<=n;j++){
			if(sum==key){
				ant++;
				sum=a[j];	
			}else{
				sum^=a[j];
			}
		}
		if(ant>max)max=ant;
	}
	printf("%d",max);
	return 0;
}