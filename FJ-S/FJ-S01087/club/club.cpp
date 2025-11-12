#include<stdio.h>	
int a[35][5];
int n,t,ant=0;
int dfs(long long sum,int num,int i){
	sum+=num;
	if(i<n){
		dfs(sum,a[i+1][1],i+1);
		dfs(sum,a[i+1][1],i+1);
		dfs(sum,a[i+1][1],i+1);
	}else{
		if(sum>ant)ant=sum;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d %d %d",a[j][1],a[j][2],a[j][3]);
		}
		dfs(0,a[1][1],1);
		dfs(0,a[1][2],1);
		dfs(0,a[1][3],1);
		printf("%d",ant);
	}
	return 0;
}

