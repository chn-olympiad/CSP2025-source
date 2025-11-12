#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],t,ans;
bool vis[5005];
void dfs(int cnt){
	if(cnt==n+1){
		int sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=a[i];
				maxn=max(maxn,a[i]);
			}
		}
		if(sum>maxn*2){
			ans=(ans+1)%mod;
		}
		return;
	}
	vis[cnt]=1;
	dfs(cnt+1);
	vis[cnt]=0;
	dfs(cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}
