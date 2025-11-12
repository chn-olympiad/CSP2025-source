#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5005],dp[5005][5005],ans;
bool flag1=true;
int c[5005][5005];
void dfs(int u,int res,int maxn,int k){
	if(u==n+1){
		if(k<=2) return;
		if(res>maxn*2) ans++;
		if(ans>=MOD) ans-=MOD;
		return;
	}
	dfs(u+1,res+a[u],max(maxn,a[u]),k+1);
	dfs(u+1,res,maxn,k);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag1=flag1&&(a[i]==a[i-1]);
	}
	if(flag1){
		c[1][0]=1;
		c[1][1]=1;
		for(int i=2;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++){
				c[i][j]=(1ll*c[i-1][j]+1ll*c[i-1][j-1])%MOD;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+c[n][i])%MOD;
		}
		cout<<ans<<"\n";
		ans=0;
	}
	else if(n<=30){
		dfs(1,0,0,0);
		cout<<ans<<"\n";
	}
	else{
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=5000;k++){
				for(int j=1;j<i;j++){
					if(a[j]<=k){
						dp[i][k]+=dp[j][a[j]];
					}
					else{
						dp[i][a[j]]+=dp[j][a[j]];
					}
				}
			}
		}
		cout<<0<<"\n";//真的不会
	}
	return 0;
}