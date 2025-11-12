#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[51000];
struct dpp{
	long long ans,sum,maxx;
}dp[51000];
bool check(long long sum,long long maxx){
	if(sum>(maxx*2)) return 1;
	else return 0;
}
long long dfs(long long i,long long sum,long long maxx,long long k){
	long long ans=0;
	if(i==n){
		if(!check(sum,maxx)&&k<3) return 0;
		else if(check(sum,maxx)&&k>=3) {return 1;} 
	} 
	if(check(sum,maxx)&&k>=3) ans++;
	for(long long j=i+1;j<=n;j++){
		ans+=dfs(j,sum+a[j],max(maxx,a[j]),k+1);
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++) ans+=dfs(i,a[i],a[i],1);
	cout<<ans;
//	for(long long i=1;i<=n;i++){
//		for(long long j=n;j>=1;j--){
//			if(check(a[i]+dp[j].sum,max(dp[i].maxx,dp[j].maxx))){
////				if(dp[i].ans<dp[j].ans+1){
//					dp[i].ans+=(dp[j].ans+1)%998244353;
//					dp[i].sum+=+a[i];
//					dp[i].maxx=max(a[i],dp[j].maxx);
////				}
//			}
//		}
//	}
//	cout<<dp[n].ans;
	return 0;
}

