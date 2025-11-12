#include <bits/stdc++.h>
using namespace std;
//I love CCF , thanks you CCF , thanks you give me T4 60pts I love you CCF 
const long long MOD=998244353;
const int N=5050;
int n,a[N];
long long ans,dp[N];
void dfs(int now,int cnt,long long sum,int ma){
	if(now==n+1){
		if(cnt>=3&&sum>2ll*ma){
			ans++;
			if(ans>=MOD) ans-=MOD;
		}
		return ;
	}
	dfs(now+1,cnt,sum,ma);
	dfs(now+1,cnt+1,sum+1ll*a[now],max(ma,a[now]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		//Êä³ö2^n-n-1
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			if(ans>=MOD) ans-=MOD;
		}
		ans=(ans-(n%MOD)+MOD)%MOD;
		ans=(ans-1+MOD)%MOD;
		cout<<ans;
		return 0;
	}
	//baoli make everythings possible
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
