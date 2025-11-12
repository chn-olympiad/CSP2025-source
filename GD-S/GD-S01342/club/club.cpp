#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}

const int N=205;
int dp[N][N][N],a[N][3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		memset(dp,0,sizeof(dp));
		int n=read(),ans=0;
		for(int i=1;i<=n;++i) a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		for(int x=0;x<n;++x){
			for(int i=0;i<=x&&i<=(n>>1);++i){
				for(int j=0;j<=x&&j<=(n>>1);++j){
					if(i+j>x) continue;
					int k=x-i-j;
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[x+1][0]);
					dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[x+1][1]);
					dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+a[x+1][2]);
				}
			}
		}
		for(int i=0;i<=(n>>1);++i){
			for(int j=(n>>1)-i;j<=(n>>1);++j){
//				printf("%d %d %d:%d\n",i,j,n-i-j,dp[i][j][n-i-j]);
				if(n-i-j>(n>>1)) continue;
				ans=max(ans,dp[i][j][n-i-j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
