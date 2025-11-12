#include<stdio.h>
long long ant=0;
int n,a[5000];
void dfs(int n1,int max,int sum,int a1,int i){
	if(a1>max)max=a1;
	sum+=a1;
	if(n1>=3){
		if(sum>2*max){
			ant++;
		}
	}
	i++;
	for(;i<=n;i++){
		dfs(n1+1,max,sum,a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		dfs(1,0,0,a[i],i);
	}
	printf("%d",ant%998244353);
	return 0;
}