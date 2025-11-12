#include<stdio.h>
const int N=1e5+5;
int T,n,w[N][3],a[N][3],ans=0;
int max(int x,int y){
	return (x>y)?x:y;
}
void dfs(int pos,int x,int y,int z,int num){
	if(pos>n){
		ans=max(ans,num);
		return;
	}
	if(x<n/2)dfs(pos+1,x+1,y,z,num+w[pos][0]);
	if(y<n/2)dfs(pos+1,x,y+1,z,num+w[pos][1]);
	if(z<n/2)dfs(pos+1,x,y,z+1,num+w[pos][2]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int g[3]={0,0,0};
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&w[i][0],&w[i][1],&w[i][2]);
			a[i][0]=a[i-1][0]+w[i][0];
			a[i][1]=a[i-1][1]+w[i][1];
			a[i][2]=a[i-1][2]+w[i][2];
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
