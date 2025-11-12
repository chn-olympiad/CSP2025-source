#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10007][10007],b[15][10007],vis[10007][10007],ans = 2147483647;
void dfs(int x,int sumcost,int index){
	if(index==n-1){
		ans = min(ans,sumcost);
	}else{
		for(int i = 1;i<=n;i++){
			if(i!=x&&a[i][x]&&vis[i][x]==0&&vis[x][i]==0){
				vis[i][x] = 1;
				vis[x][i] = 1;
				dfs(i,a[i][x]+sumcost,index+1);
				vis[i][x] = 0;
				vis[x][i] = 0;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i<=m;i++){
		int s,e;
		cin >> s >> e;
		cin >> a[s][e];
		a[e][s] = a[s][e];
	}for(int i = 1;i<=k;i++){
		cin >> b[i][0];
		for(int j = 1;j<=n;j++){
			cin >> b[i][j];
			if(i!=1) b[i][j] = min(b[i][j],b[i-1][j]);
		}
	}for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i!=j&&a[i][j]){
				a[i][j] = min(a[i][j],b[k][i]+b[k][j]);
				a[j][i] = a[i][j];
			}else if(i!=j&&!a[i][j]){
				a[i][j] = b[k][i]+b[k][j];
				a[j][i] = a[i][j];
			}
		}
	}dfs(1,0,0);
	cout << ans;
	return 0;
} 
