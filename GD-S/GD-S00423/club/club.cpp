#include<bits/stdc++.h>
int n,a[3][100010],ans;
void dfs(int k,int x,int y,int z,int h){
	if(k>n){
		ans=std::max(ans,h);
		return ;
	}
	if(x) dfs(k+1,x-1,y,z,h+a[0][k]);
	if(y) dfs(k+1,x,y-1,z,h+a[1][k]);
	if(z) dfs(k+1,x,y,z-1,h+a[2][k]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof a);
		ans=0;
		scanf("%d",&n); 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
		}
		dfs(1,n/2,n/2,n/2,0);
		printf("%d\n",ans);
	}
	return 0;
}
