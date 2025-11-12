#include<cstdio>
#include<algorithm>
#define M 998244353
int ans,n,a[5005],f[5005];
int oi(int n){
	int m=1;
	for(int i=1;i<=n;i++){
			m=m*i%M;
	}
	return m;
}
int zuhe (int n,int m){
	return oi(n)/oi(n-m)/oi(m)%M;
}
void dfs(int m,int k,int sum,int s){//m是一共要选多少数，sum是累加和，k是步数,s是到哪了
	if(k==m+1) {
		if(a[s]*2<sum)ans=(ans+1)%M;
		return ;
	}
	for(int i=s+1;i<=n;i++){
		dfs(m,k+1,sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	std::sort(a+1,a+n+1);
	if(n<3) {
		printf("0");
	}
	else if(a[n]==1){
	for(int i=3;i<=n;i++){
		ans=(ans+zuhe(n,i))%M;
	}
	printf("%d",ans);
	}else{
		for(int i=3;i<=n;i++){
			dfs(i,1,0,0);
		}
		printf("%d",ans);
	}
	return 0;
}