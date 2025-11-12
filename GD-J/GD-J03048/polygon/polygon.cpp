#include<bits/stdc++.h>

using namespace std;
int a[50010];
bool vis[50010];
int n;
int ans=0;
map<pair<long long,long long>,bool> mp;
map<pair<int,int>,bool> mq;
void dfs(int u,int maxs,int cnt){
	if(u>n+1)return ;
	if(u>3){
		if(maxs*2<cnt&&mp[{maxs,cnt}]!=1&&mq[{u,cnt}]!=1){
			cout<<maxs<<" "<<cnt<<'\n';
			mp[{maxs,cnt}]=1;
			mq[{u,cnt}]=1;
			ans++;
		}
		//else return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;
		dfs(u+1,max(maxs,a[i]),cnt+a[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
