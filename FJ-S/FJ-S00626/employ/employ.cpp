#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,a[505],ans,vis[505];
string s;
void dfs(ll fq,ll dp){
	if(dp>n){
		if(dp-fq-1>=m){
			
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[dp-1]=='0'||(a[i]<=fq))dfs(fq+1,dp+1);
			else dfs(fq,dp+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,1);
	printf("%lld",ans);
	return 0;
	/*
3 2
101
1 1 2
	*/
} 
/*2025.11.1CSP-S游记
14.31 发卷子
15.32 T1不会，暴力期望20+5pts
15.55 T2不会，暴力期望32pts
16.30 T3不会，暴力期望25pts 
16.44 T4不会，暴力期望20pts
共期望102pts 
rp++ 
*/ 
