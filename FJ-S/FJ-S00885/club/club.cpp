#include<bits/stdc++.h>
using namespace std;
int T;
int n,x[100005],y[100005],z[100005],vis[100005],ans;
int a,b,c;
void init(){
	memset(vis,0,sizeof(vis));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	a=b=c=0;
	ans=0;
}
namespace get_40{
	int get_ans(){
		int dp[20][20][20],res=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					for(int u=n/2;u>=0;u--){
						if(j!=0){
							dp[j][k][u]=max(dp[j][k][u],dp[j-1][k][u]+x[i]);
						}
						if(k!=0){
							dp[j][k][u]=max(dp[j][k][u],dp[j][k-1][u]+y[i]);
						}
						if(u!=0){
							dp[j][k][u]=max(dp[j][k][u],dp[j][k][u-1]+z[i]);
						}
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>(n/2)) continue;
				res=max(res,dp[i][j][k]);
			}
		}
		return res;
	}
}
namespace get_5{
	int get_ans(){
		int dp[150][150],res=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=0;j--){
				for(int k=n/2;k>=0;k--){
					if(j!=0){
						dp[j][k]=max(dp[j][k],dp[j-1][k]+x[i]);
					}
					if(k!=0){
						dp[j][k]=max(dp[j][k],dp[j][k-1]+y[i]);
					}
				}
			}
		}
		return dp[n/2][n/2];
	}
}
void dfs(int now,int sum){
	if(now>n){
		ans=max(ans,sum);
	}
	if(a<n/2){
		a++;
		dfs(now+1,sum+x[now]);
		a--;
	}
	if(b<n/2){
		b++;
		dfs(now+1,sum+y[now]);
		b--;
	}
	if(c<n/2){
		c++;
		dfs(now+1,sum+z[now]);
		c--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		int f2=1,f3=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
			if(y[i]!=0) f2=0;
			if(z[i]!=0) f3=0;
		}
		if(n<=10){
			dfs(1,0);
		}else if(f2==1&&f3==1){
			sort(x+1,x+n+1,greater<int>());
			for(int i=1;i<=n/2;i++){
				ans+=x[i];
			}
		}else if(n<=30){
			ans=get_40::get_ans();
		}else if(f3==1&&n<=200){
			ans=get_5::get_ans();
		}else{
			for(int i=1;i<=n;i++){
				ans+=max({x[i],y[i],z[i]});
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
