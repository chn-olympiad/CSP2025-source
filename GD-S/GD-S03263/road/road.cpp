#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const long long N=1e100;
int ans=N;
int a[10010][10010];//每条路的权重，-1代表没路 
bool b[10010];//判断城市是否被遍历过 
int dfs(int x){
	int sum=0,vis=N,y,z;//sum是费用 
	b[x]=1; 
	for(int i=1;i<=n;i++){
		if(!b[i]){
			y=a[x][i];
			z=dfs(i);
			vis=min(vis,y+z);
			sum=vis;
		}
//    ┬┴┬┌─　●─┬─　　│─┼─┐　●├─┤○
//    ┴┬┴├┬　┌─┼─　│◎　│　│　○└┬┘●
//    ─┼─││　│　│　　││─┴─┴　──┼──
//    ●│○││　┴─┼─　　│○　　●　／　│　＼
	}
	b[x]=0;
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=-1;
		}
	} 
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=w;
		a[v][u]=w;
	} 
	for(int i=1;i<=n;i++) ans=min(ans,dfs(i));
	printf("%d",ans);
}
