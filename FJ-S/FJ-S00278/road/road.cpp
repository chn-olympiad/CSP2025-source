#include<bits/stdc++.h>
using namespace std;
int n,ans,m,k;
struct node{
	int u,v;
	int qz;
}a[1000005];
int u,v,w;
bool vis[10005];
void dfs(int w,int sum){
	if(vis[w])return;
	if(w==k){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		dfs(a[i].u,sum+a[i].qz);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=0x3f3f3f3f;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].qz=w;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
