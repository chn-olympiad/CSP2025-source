#include<stdio.h>
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,a[1005]={0};
	scanf("%d %d",&n,&q);
	char c;
	for(int j=1;j<=n;j++){
		int i=1,i2=1;
		while(getchar()=='a')i++;
		while(getchar()!=' ');
		while(getchar()=='a')i2++;
		a[j]=i-i2;
	}
	int i=1,i2=1,ant=0;
	while(getchar()=='a')i++;
	while(getchar()!=' ');
	while(getchar()=='a')i2++;
	int i3=i-i2;
	for(int j=1;j<=n;j++){
		if(a[j]==i3)ant++;
	}
	for(int i=1;i<=q;i++){
			printf("%d",ant);
	}
	return 0;
}
