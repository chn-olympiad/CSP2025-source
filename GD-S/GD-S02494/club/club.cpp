#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],dp[205][205][205],nn,ans=0,b[100005];
bool A;
void dfs(int dep,int cnt1,int cnt2,int cnt3,int sum){
	if(dep>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){	
		if(cnt1<nn)dfs(dep+1,cnt1+1,cnt2,cnt3,sum+a[dep][1]);
		if(cnt2<nn)dfs(dep+1,cnt1,cnt2+1,cnt3,sum+a[dep][2]);
		if(cnt3<nn)dfs(dep+1,cnt1,cnt2,cnt3+1,sum+a[dep][3]);
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		A=1;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0)A=0;
		}
		nn=n/2;
		ans=0;
		if(n<=4){
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}else if (A){
			for(int i=1;i<=n;++i)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>nn;--i)ans+=b[i];
			printf("%d\n",ans);
		}else{
			memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i){
			for(int j=0;j<=min(i,nn);++j){
				for(int k=0;k<=min(i-j,nn);++k){
					if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(j+k<i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		for(int i=0;i<=nn;++i)
			for(int j=0;j<=min(n-i,nn);++j)
				ans=max(ans,dp[n][i][j]);
		printf("%d\n",ans);
		}
	}
	return 0;
}
