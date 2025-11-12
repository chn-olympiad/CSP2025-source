#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+2;
int maxans=-1;
int dp[MAXN][4];
int sum[MAXN][4][4];
int a[MAXN][4];
int t,n,maxsum;
int dsum[4];
void dfs(int x,int pre){
	if(x==n){
		for(int i=1;i<=3;i++){
			if(dsum[i]<maxsum) maxans=max(maxans,pre+a[x][i]);
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(dsum[i]>=maxsum) continue;
		dsum[i]++;
		dfs(x+1,pre+a[x][i]);
		dsum[i]--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int iop=1;iop<=t;iop++){
		scanf("%d",&n);
		maxsum=n>>1;
		for(int i=1;i<=n;i++){
			dsum[i]=0;
			for(int j=1;j<=3;j++){
				dp[i][j]=0;
				for(int k=1;k<=3;k++){
					sum[i][j][k]=0;
				}
				scanf("%d",&a[i][j]);
			}
		}
		if(n<=15){
			maxans=-1;
			dfs(1,0);
			printf("%d\n",maxans);
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(sum[i-1][j][k]<maxsum){
						dp[i][k]=max(dp[i][k],dp[i-1][j]+a[i][k]);
						if(dp[i][k]==dp[i-1][j]+a[i][k]){
							memcpy(sum[i][k],sum[i-1][j],sizeof(sum[i-1][j]));
							sum[i][k][k]++;
						}
					} 
				}
			}
//			if(sum[i-1][1]<maxsum){
//				dp[i][1]=max(dp[i][1],dp[i-1][1]+a[i][1]);
//				dp[i][2]=max(dp[i][2],dp[i-1][1]+a[i][2]);
//				dp[i][3]=max(dp[i][3],dp[i-1][1]+a[i][3]);
//			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				cout<<dp[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
//		cout<<sum[3][1][2]<<'\n';
		printf("%d\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/