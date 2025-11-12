#include<bits/stdc++.h>
using namespace std;
struct stu{
	int v,w;
};
vector<stu> arr[int(1e6+10)];
bool vis[int(1e4+10)];
int ans=0x7fffffff;int m,n,k;
void dfs(int x,int cnt,int s){
	if(vis[x] || cnt>=ans) return;
	vis[x]=1;
	s++;
	//cout<<s<<'\n';
	if(s==n){
		ans=min(cnt,ans);
		//cout<<'a';
		vis[x]=0;
		return;
	}
	for(auto i:arr[x]){
		dfs(i.v,cnt+i.w,s);
	}
	vis[x]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		arr[u].push_back({v,w});
		arr[v].push_back({u,w});
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
