#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5010;
int n,arr[N];
long long ans;
void dfs(int d,int sum,int maxn,int sm){
	if(sm>=3)if(sum+arr[d]>max(maxn,arr[d])*2)ans++,ans%=MOD;
	if(d==n)return;
	for(int i=d+1;i<=n;i++)dfs(i,sum+arr[d],max(maxn,arr[d]),sm+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1)f=0;
	}
	if(f){
		long long dp[N];
		dp[3]=n*(n-1)%MOD*(n-2)%MOD/6;
		for(int i=4;i<=n;i++)dp[i]=dp[i-1]*(n-i)%MOD/i;
		for(int i=1;i<=n;i++)ans+=dp[i],ans%=MOD;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)dfs(i,0,arr[i],1);
	cout<<ans;
	return 0;
}