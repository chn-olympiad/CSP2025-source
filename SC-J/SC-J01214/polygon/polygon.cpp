#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
const int mod=998244353;
int n,a[maxn],maxx=INT_MIN;
int dp[25][2005][105];
int dp2[5005][5005][1];
int dfs1(int x,int sum,int maxn){
	if(dp[x][sum][maxn]!=-1) return dp[x][sum][maxn];
	if(x==n+1){
		if(sum>2*maxn) return 1;
		return 0;
	}
	int ans=0;
	ans+=dfs1(x+1,sum+a[x],max(maxn,a[x]));
	ans%=mod;
	ans+=dfs1(x+1,sum,maxn);
	ans%=mod;
	return dp[x][sum][maxn]=ans;
}
int dfs2(int x,int sum,int maxn){
	if(dp2[x][sum][maxn]!=-1) return dp2[x][sum][maxn];
	if(x==n+1){
		if(sum>2*maxn) return 1;
		return 0;
	}
	int ans=0;
	ans+=dfs2(x+1,sum+a[x],max(maxn,a[x]));
	ans%=mod;
	ans+=dfs2(x+1,sum,maxn);
	ans%=mod;
	return dp2[x][sum][maxn]=ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(maxx==1){
		memset(dp2,-1,sizeof(dp2));
		cout<<dfs2(1,0,0);
	}
	else{
		memset(dp,-1,sizeof(dp));
		cout<<dfs1(1,0,0);
	}
	return 0;
}