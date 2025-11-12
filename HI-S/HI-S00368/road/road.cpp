#include <bits/stdc++.h>
using namespace std;

const int MAXM=1e6+10,MAXN=1e4+10;

int n,m,k;
int u,v,t;
int ans=0;
int dp[MAXN][MAXN];
int ji[MAXN];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(dp,-1,sizeof(dp));
	memset(ji,0,sizeof(ji));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&t);
		dp[u][v]=t;
//		dp[v][u]=t;
	}
	if(k==0){
		for(int i=n;i>=1;i--){
			for(int j=n;j>=1;j--){
				if(dp[i][j]!=-1){
					if(ji[j]==0) ji[j]=dp[i][j]+ji[i];
					else ji[j]=min(ji[j],dp[i][j]+ji[i]);
				//	printf("ji[%d]=%d\n",j,ji[j]);
				}
			}
		}
		for(int i=1;i<=n;i++) ans=ans+ji[i];
		printf("%d",ans);
	}
	return 0;
}

