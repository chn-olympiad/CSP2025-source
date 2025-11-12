#include<stdio.h>
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m,b[505]={0};
	scanf("%d %d",&n,&m);
	getchar();
	char a[505]={0};
	scanf("%s",&a);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	printf("%lld",sum);
	return 0;
}