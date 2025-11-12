#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[501],ans;
bool vis[501];
void dfs(int i,int t,int cnt){
	if(i==n){
		if(cnt>=m)ans=(ans+1)%mod;
		return;
	}
	if(n-i+cnt<m)return;
	for(int k=0;k<n;k++){
		if((1<<k)&t){
			if(vis[i]==0||c[k]<=i-cnt)dfs(i+1,t-(1<<k),cnt);
			else dfs(i+1,t-(1<<k),cnt+1);
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		vis[i]=c-'0';
	}
	for(int i=0;i<n;i++)cin>>c[i];
	dfs(0,(1<<n)-1,0);
	cout<<ans;
	return 0;
}
