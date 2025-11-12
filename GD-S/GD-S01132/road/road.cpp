#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
struct no{
	int v,w;
};
vector<no> a[10020];
int dis[10010];
int c[20];
int n,m,k;
int vis[10010];
int ans;
void dfs(int u,int cnt,int sum){
	if(ans!=0&&sum>=ans)return;
	if(cnt==n){
		if(ans==0){
			ans=sum;
			return;
		}
		ans=min(ans,sum);
		return;
	}
	for(auto x:a[u]){
		if(dis[x.v]==0||dis[x.v]!=sum){
			int y=dis[x.v];
			dis[x.v]=sum;
			if(y==0)dfs(x.v,cnt+1,sum+x.w);
			else dfs(x.v,cnt,sum);
			dis[x.v]=y;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int iijj=0;
			cin>>iijj;
			a[j].push_back({i+n,iijj});
		}
	}
	if(k==0){
		vis[1]=1;
		dfs(1,1,0);
		cout<<ans;
	}
}
