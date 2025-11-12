#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],dp[5001][5001],c[5001],ans;
bool T[5001][5001];
bool cmp(int x,int y){
	return x>y;
}
int dfs(int x,int t,int y){
	if(x<0){
		dp[x][t]=c[n-y];
		return dp[x][t];
	}
	T[x][t]=1;
	for(int i=t;i<=n;i++){
		if(!T[x-a[i]][i+1])dfs(x-a[i],i+1,y+1);
		dp[x][t]=(dp[x][t]+dp[x-a[i]][i+1])%mod;
	}
	return dp[x][t];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	c[0]=1;
	for(int i=1;i<=n;i++){
		int o=1;
		for(int j=1;j<=i;j++){
			o=(o*(i-j+1)/j)%mod;
			c[i]=(c[i]+o)%mod;
		}
	}
	for(int i=1;i<=n-2;i++){
		ans=(dfs(a[i],i+1,1)+ans)%mod;
	}
	cout<<ans;
    return 0;
}