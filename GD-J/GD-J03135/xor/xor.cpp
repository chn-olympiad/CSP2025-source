#include<bits/stdc++.h>
using namespace std;

int n,k;
int rht[500010],vis[500010];
int ans;

void dfs(int now,int sum){
	if(vis[now]>=sum){
		return ;
	}
	ans=max(ans,sum);
	vis[now]=sum;
	if(now>n){
		return;
	}
	for(int i=now;i<=n;i++){
		if((rht[i]^rht[now-1])==k){
			dfs(i+1,sum+1);
		}
	}
	dfs(now+1,sum);
}

int main( ){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		rht[i]=rht[i-1]^a;
		vis[i]=-1;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
