#include<cstdio>
int n,a[5],ans,max=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		max=a[i]>max?a[i]:max;
	}
	if(a[1]+a[0]+a[2]>2*max)
	printf("1");
	else printf("0");
	return 0;
} 
