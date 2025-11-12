#include<bits/stdc++.h>
using namespace std;
const int N=1e5+111;
int T,n,dp[N],a[N][3],ans=0;

void dfs(int d,int d1,int d2,int d3,int sum){
	if(d1>n/2 || d2>n/2 || d3>n/2){
		return ;
	}
	if(d>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(d+1,d1+1,d2,d3,sum+a[d][1]);
	dfs(d+1,d1,d2+1,d3,sum+a[d][2]);
	dfs(d+1,d1,d2,d3+1,sum+a[d][3]);

	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}

	return 0;
}

