#include<bits/stdc++.h>
using namespace std;
int d[100005][5],n,ans;
void dfs(int x,int a,int b,int c,int sum){
	if(x==n+1){
		ans=max(ans,sum);
	}
	if(a<n/2) dfs(x+1,a+1,b,c,sum+d[x][1]);
	if(b<n/2) dfs(x+1,a,b+1,c,sum+d[x][2]);
	if(c<n/2) dfs(x+1,a,b,c+1,sum+d[x][3]);
}
int main(){
	int T;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&d[i][j]);
			}
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
}