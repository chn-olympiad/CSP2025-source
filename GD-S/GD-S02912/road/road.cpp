#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=1e18,c[15],a[15][20005],dis[20005];
vector<int> g[20005],w[20005];
bool f[15],vis[20005];
struct node{
	int x,d;
};
bool operator>(const node &x,const node &y){
	return x.d>y.d;
}
priority_queue<node,vector<node>,greater<node>>q;
int prim(){
	int sum=0;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push({1,0});
	while(!q.empty()){
		int u=q.top().x;
		q.pop();
		if(vis[u])continue;
		vis[u]=true;
		sum+=dis[u];
		if(u>n){
			for(int i=1;i<=n;i++){
				if(dis[i]>a[u-n][i]){
					dis[i]=a[u-n][i];
					q.push({i,dis[i]});
				}
			}
		}else{
			for(int i=0;i<g[u].size();i++){
				int v=g[u][i];
				if(dis[v]>w[u][i]){
					dis[v]=w[u][i];
					q.push({v,dis[v]});
				}
			}
			for(int i=1;i<=k;i++){
				if(f[i]&&dis[i+n]>a[i][u]){
					dis[i+n]=a[i][u];
					q.push({i+n,dis[i+n]});
				}
			}
		}
	}
	return sum;
}
void dfs(int step,int cur){
	if(step>k){
		ans=min(ans,cur+prim());
		return;
	}
	dfs(step+1,cur);
	f[step]=true;
	dfs(step+1,cur+c[step]);
	f[step]=false;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x].push_back(y);
		w[x].push_back(z);
		g[y].push_back(x);
		w[y].push_back(z);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		bool flag=(c[i]==0);
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0){
				flag=false;
			}
		}
		if(flag){
			cout<<0;
			return 0;
		}
	}
	dfs(1,0);
	cout<<ans;]
	return 0;
}
