#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u[100009],v[100009],w[100009],k,g[1009][1009];
int ans;
int c[100009],a[1009][1009];
int dfs(int q,int step,int p){
		if(q>n||p>n)return 0;
	 if(g[q][p]==0){
		 step++;
		 ans+=dfs(q+1,step,p)+dfs(q+1,step,p)+min(w[step],a[q][p]);
	 }
	 if(g[q][p]==1){
		 return min(w[step],a[q][p]);
	 }
	 return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		g[u[i]][v[i]]=1;
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		c[i]=c[i]*2;
		for(j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ans=dfs(0,1,1);
	cout<<ans;
}
//Ren5Jie4Di4Ling5%
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
