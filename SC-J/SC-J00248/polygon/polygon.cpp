#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],vis[5005];
long long ans;
void dfs(long long cnt,int mx,int sum,int js){
	if(js==n+1){
		ans=max(ans,cnt);
		return;
	} 
	if(vis[js]==1) return;
    vis[js]=1;
	if(js>3){
		if(sum+a[js]>max(mx,a[js])*2){
			dfs((cnt+1)%mod,max(mx,a[js]),sum+a[js],js+1);
			dfs(cnt,mx,sum,js+1);
			vis[js]=0;
		}
		else{
			dfs(cnt,max(mx,a[js]),sum+a[js],js+1);
			dfs(cnt,mx,sum,js+1);
			vis[js]=0;
		}
	}
    if(js<=3){
     	dfs(cnt,max(mx,a[js]),sum+a[js],js+1);
     	dfs(cnt,mx,sum,js+1);
		vis[js]=0;
	}
	
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,-1e9,0,1);
	cout<<ans;
	return 0;
} 
