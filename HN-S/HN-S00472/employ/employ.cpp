#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long a[N],sum[N],vis[N],n,m,res=0;
void dfs(long long v,long long ans){
	for(int i=1;i<=n;i++){
		cout<<vis[i];
	}
	if(v>n){
		if(ans>=m){
			res++;
		}
		return ;
	}
	if(ans+n-v<m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			if(a[i]>sum[i]){
				vis[i]=1;
				dfs(v+1,ans+1);
				vis[i]=0;
			}else{
				vis[i]=1;
				dfs(v+1,ans);
				vis[i]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	bool p=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			p=0; 
		} 
		sum[i]=sum[i-1]+s[i]-'0';
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(p){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<res;
	/*
	/////////////////////////////////////////dp[i][j]=运行到i且录用了j个人的方案数 
	*/ 
	return 0;
}
