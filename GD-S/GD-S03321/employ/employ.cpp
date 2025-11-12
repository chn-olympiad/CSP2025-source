#include<iostream>
using namespace std;
const int N=1e5+7,mod=998244353;
int n,m,t[N],c[N],ans;
int rk[N];bool use[N];
void dfs(int dep){
	if(dep>n){
		int in=0,out=0;
		for(int i=1;i<=n;i++) if(!t[i]||out>=c[rk[i]]) out++; else in++;
		if(in>=m){
//			for(int i=1;i<=n;i++) printf("%d ",rk[i]); printf("\n");
			ans=(ans+1)%mod;
		}
	}
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		use[i]=1;rk[dep]=i;
		dfs(dep+1);
		use[i]=0;rk[dep]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++) scanf("%1d",&t[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2


*/
