#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],s[1000010],pre[1000010],ans,flag=1,dp[5005][5005];
void dfs(int k,int sum,int mmax){
	if(k==n+1){
		if(sum>mmax*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(k+1,sum+a[k],max(mmax,a[k]));
	dfs(k+1,sum,mmax);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]){
			flag=0;
		}
	}
	if(flag){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j==0||j==i){
					dp[i][j]=1;
					continue;
				}
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				dp[i][j]%=998244353;
			}
		}
		for(int i=3;i<=n;i++){
			ans+=dp[n][i];
			ans%=998244353;
		}
		printf("%d",ans);
		return 0;
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
