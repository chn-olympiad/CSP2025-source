#include<cstdio>
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,z,u,k,m;
	scanf("%d %d",&x,y);
	for(int i=1;i<=x*y;i++){
		scanf("%d",&a[i]);
	}
	z=a[1];
	for(int o=1;o<=x*y;o++){
		for(int i=x*y;i>1;i--){
			for(int j=1;;){
				int n;
				if(a[i]<a[i-j]) break;
				if(a[i]>a[i-j]){
					n=a[i];
					a[i]=a[i-j];
					a[i-j]=n;
				}
			}
		}	
	}
	for(int i=1;i<=x*y;i++){
		if(a[i]==z) m=i;
	}
	u=m%x;
	k=m/x;
	if(k/2==0){
		printf("%d %d",k+1,u);
	}else{
		printf("%d %d",k+1,x-u);
	}
	return 0;
}

