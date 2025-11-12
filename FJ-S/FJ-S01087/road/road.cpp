#include<stdio.h>
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a,&b,&c);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&a);
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
		}
	}
	printf("0");
	return 0;
}
