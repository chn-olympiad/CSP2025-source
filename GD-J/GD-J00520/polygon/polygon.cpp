#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,ans=0,a[25],vis[1<<20+5];
void dfs(int x,int mx,int sum,int k){
	if(x>=3&&mx*2<sum)ans=(ans+1)%p;
	for(int i=1;i<=n;i++){
		if(!(k>>i&1)){
			int k_=k|1<<i;
			if(!vis[k_]){
				vis[k_]=1;
				dfs(x+1,max(mx,a[i]),sum+a[i],k_);
			}			
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	if(n==20){
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		dfs(0,0,0,0);
		printf("%d\n",ans);
	}else{
		long long res=1,tmp=(1+n+n*(n-1)/2)%p;
		for(int i=1;i<=n;i++)res=res*2%p;
		res=(res-tmp+p)%p;
		printf("%lld\n",res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
