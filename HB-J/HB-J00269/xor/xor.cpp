#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,a[N],k,flag=1,ans,dp[N];
void dfs(int pos,int now,int cnt){
	dp[pos]=max(dp[pos],cnt);
	if(cnt<dp[pos])return;
	if(pos==n+1){
		ans=max(ans,cnt);
		return;
	}if(a[pos]==k||((now^a[pos])==k)){
		dfs(pos+1,0,cnt+1);
		return;
	}else{
		dfs(pos+1,now^a[pos],cnt);
		if(cnt+1>=dp[pos+1])dfs(pos+1,0,cnt);
		return;
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=0;
	}if(flag){
		int now=0,cnt=0;
		for(int i=1;i<=n;i++){
			now^=a[i];
			if(a[i]==k||now==k){
				cnt++;
				now=0;
			}
		}ans=cnt;
		now=0;
		cnt=0;
		for(int i=n;i>=1;i--){
			now^=a[i];
			if(a[i]==k||now==k){
				cnt++;
				now=0;
			}
		}
		ans=max(cnt,ans);
	}else{
		dfs(1,0,0);
	}cout<<ans;
	return 0;
}
