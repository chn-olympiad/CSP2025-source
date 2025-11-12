#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
int a[N],b[N],c[N];
int dp[700][700][700];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i])flag1=0;
			if(c[i])flag2=0;
		}
		if(flag1&&flag2){
			sort(a+1,a+n+1);
			int ans=0; 
			for(int i=n;i>=n/2+1;i--)ans+=a[i];
			printf("%d\n",ans);
			continue; 
		}
		int w=n/2;
		for(int i=0;i<=w;i++)for(int j=0;j<=w;j++)for(int k=0;k<=w;k++)dp[i][j][k]=-0x3f3f3f3f;
		dp[0][0][0]=0;
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j1=min(w,i);j1>=0;j1--){
				for(int j2=min(w,i-j1);j2>=0;j2--){
					for(int j3=min(w,i-j1-j2);j3>=0;j3--){
						if(j1-1>=0)dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1-1][j2][j3]+a[i]);
						if(j2-1>=0)dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1][j2-1][j3]+b[i]);
						if(j3-1>=0)dp[j1][j2][j3]=max(dp[j1][j2][j3],dp[j1][j2][j3-1]+c[i]);
						ans=max(ans,dp[j1][j2][j3]);
						//printf("dp[%d][%d][%d]=%d\n",j1,j2,j3,dp[j1][j2][j3]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
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

