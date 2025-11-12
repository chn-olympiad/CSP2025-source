#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500001],dp[500001];
int dfs(int id){
	cout<<id<<endl;
	if(id==n){
		return 0;
	}
	if(dp[id]!=-1) return dp[id];
	int ans=0;
	int num=0;
	for(int i=id+1;i<=n;i++){
		num=num^a[i];
		if(num==k) ans=max(ans,dfs(i)+1);
		else ans=max(ans,dfs(i));
	}
	return dp[id]=ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0)<<endl;
	return 0;
}
