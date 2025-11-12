#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
const int mod=998244353;
int n;
int a[N],b[N];
int dp[N][N];
int dfs1(int t,int s){
	ll ans=0;
	int minn;
	s<a[n]+1?minn=s:minn=a[n]+1;
	if(dp[t][minn]){
		return s>b[t]?dp[t][minn]+1:dp[t][minn];
	}
	for(int i=n;i>t;i--){
		ans+=dfs1(i,s+a[i]);
	}
	ans%=mod;
	dp[t][minn]=ans;
	return s>b[t]?ans+1:ans;
}
int dfs2(int t,int s,int l){
	int ans=0;
	if(s>b[t])ans=1;
	if(l<2){
		for(int i=t+1;i<=n;i++){
			ans+=dfs2(i,s+a[i],l+1);
		}
	}
	return s>b[t]?ans+1:ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]<<1;
	}
	cout<<dfs1(0,0)%mod-dfs2(0,0,0);
	return 0;
}