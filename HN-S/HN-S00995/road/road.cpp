#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
int n,m,k;
int a[N][N];
bool vis[N][N];
int dfs(int l,int s,int sum){
	if(l == 0){
		return sum;
	}
	for(int i=1;i<=n;i++){
		if(a[s][i] && !vis[i][s] && i!=s){
			vis[i][s] = vis[s][i] = 1;
//			printf("%d %d %d\n",l-1,i,sum+a[s][i]);
			dfs(l-1,sum+a[s][i],i);
			vis[i][s] = vis[s][i] = 1;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0){
		int ans = 999999999;
		for(int i=1;i<=m;i++){
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			a[u][v] = a[v][u] = w;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]){
					for(int k=1;k<=n;k++){
						if(a[k][j])a[i][j] = max(a[i][j],a[k][j]);
					}
				}
				else {
					for(int k=1;k<=n;k++){
						if(a[k][j]&&a[i][j])a[i][j] = max(a[i][j],a[k][j]);
						else if(!a[i][j]) a[i][j] = a[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i != j&&a[i][j]){
					vis[i][j] = vis[j][i] = 1;
					int p=dfs(n,j,a[i][j]);
					vis[i][j] = vis[j][i] = 0;
//					printf("\n%d %d %d %d\n",i,j,ans,p);
					if(p < ans)ans = p;
					
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}

