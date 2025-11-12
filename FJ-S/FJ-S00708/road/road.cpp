#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,MAXN=1e18;
int n,m,k,u,v,w,c[N],a,ans=MAXN;
bool vis[N];
struct node{
	int to,w;
};
vector<node> q[N];
bool operator<(node a,node b){
	return a.w>b.w;
}
priority_queue<node> qq;
int solve(int x){
	memset(vis,0,sizeof(vis));
	int cnt=0,res=0;
	if(!x)qq.push((node){1,0});
	for(int i=0;i<k;i++){
		if((1<<i)&x){
			qq.push((node){n+i+1,0});
			res+=c[i+1]; 
		}
	}
	while(!qq.empty()){
		u=qq.top().to;
		int cost=qq.top().w;
		qq.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u<=n)cnt++; 
		res+=cost;
		int len=q[u].size();
		for(int i=0;i<len;i++){
			qq.push((node){q[u][i].to,q[u][i].w});
		}
	}
	if(cnt==n)return res;
	return MAXN;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q[u].push_back((node){v,w});
		q[v].push_back((node){u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a;
			q[n+i].push_back((node){j,a});
		}
	}
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,solve(i));
	}
	cout<<ans;
	return 0;
} 
