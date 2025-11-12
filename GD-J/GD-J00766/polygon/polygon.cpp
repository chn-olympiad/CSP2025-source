#include<bits/stdc++.h>
int n=0,l[5005],k[5005],m[5005][5005],dp[5005][5005];
int dfs(int pl,int pr){
	if(m[pl][pr])return m[pl][pr];
	if(pl==pr){
		m[pl][pr]=l[pl];
		return l[pl];
	} 
	for(int i=pl;i<pr;i++)
		m[pl][pr]=std::max(dfs(pl,i),dfs(i+1,pr));
	return m[pl][pr];
}
int po(int pl,int pr,int num){
	if(dp[pl][pr])return dp[pl][pr];
	if(pr-pl+1<=3){
		if(num>m[pl][pr]*2)return dp[pl][pr]=1;
		else return dp[pl][pr]=0;
	}
	int ans=0;
	if(num>m[pl][pr]*2)ans++;
	ans+=po(pl+1,pr,num-l[pl])+po(pl,pr-1,num-l[pr]);
	return dp[pl][pr]=ans;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		k[i]=k[i]+l[i];
	}
	dfs(1,n);
	po(1,n,k[n]);
	printf("%d",dp[1][n]);
	return 0;
}
