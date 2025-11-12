#include<bits/stdc++.h>
using namespace std;
int T,n;
int vis[3],bz[100005],dp[2][105][105][105],a[100005][4];
int ans;
inline int read(){
	int ans=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
inline int Min(int a,int b){
	return a<b?a:b;
}
inline int Max(int a,int b){
	return a>b?a:b;
}
int cun[100005];
bool cmp(int x,int y){
	return x>y;
}
void Sol(){
	cun[0]=0;
	for(int i=1;i<=n;i++){
		cun[++cun[0]]=a[i][1];
	}
	sort(cun+1,cun+1+cun[0],cmp);
	for(int i=1;i<=(n/2);i++){
		ans+=cun[i];
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		bool bz=0;
		ans=0ll;
		n=read();
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			bz|=(a[i][2]>0)|(a[i][3]>0);
		}
		if(bz==0){
			Sol();
			continue;
		}
		for(int i=0;i<=(n/2);i++){
			for(int j=0;j<=(n/2);j++){
				for(int k=0;k<=(n/2);k++){
					dp[0][i][j][k]=0;
				}
			}
		}
		for(int z=1;z<=n;z++){
			int t=Min(z,n/2);
			for(int i=0;i<=t;i++){
				int ttt=Min(z-i,n/2);
				for(int j=0;j<=ttt;j++){
					int tt=Min(z-i-j,n/2);
					for(int k=0;k<=tt;k++){
						dp[z&1][i][j][k]=0;
					}
				}
			}
			for(int i=0;i<=t;i++){
				int ttt=Min(z-i,n/2);
				for(int j=0;j<=ttt;j++){
					int tt=Min(z-i-j,n/2);
					for(int k=0;k<=tt;k++){
						if(i-1>=0){
							dp[z&1][i][j][k]=Max(dp[(z&1)^1][i-1][j][k]+a[z][1],dp[z&1][i][j][k]);
							ans=Max(ans,dp[z&1][i][j][k]);
						}
						if(j-1>=0){
							dp[z&1][i][j][k]=Max(dp[(z&1)^1][i][j-1][k]+a[z][2],dp[z&1][i][j][k]);
							ans=Max(ans,dp[z&1][i][j][k]);
						}
						if(k-1>=0){
							dp[z&1][i][j][k]=Max(dp[(z&1)^1][i][j][k-1]+a[z][3],dp[z&1][i][j][k]);
							ans=Max(ans,dp[z&1][i][j][k]);
							if(dp[z&1][i][j][k]==dp[z&1][i][j][k-1]){
								break;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
