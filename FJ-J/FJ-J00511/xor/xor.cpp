#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5;

int n,k;
int a[MAXN],dp[MAXN];

int dfs(int l){
	if (dp[l]!=-1) return dp[l];
	
	for (int r=l,maxx=0,sum=a[l];r<=n;r++,sum^=a[r]){
		if (sum==k){
			for (int s=r+1;s<=n;s++) maxx=max(maxx,dfs(s));
			dp[l]=maxx+1;
			return dp[l];
		}
	}
	dp[l]=0;
	return 0;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,-1,sizeof dp);
	
	int ans=0;
	for (int s=1;s<=n;s++) ans=max(ans,dfs(s));
	cout<<ans;
	
	return 0;
}
