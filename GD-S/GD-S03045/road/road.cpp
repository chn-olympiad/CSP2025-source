#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,c[20],a[20][N];
vector <pair<int,int>> g[N];


int vis[N+100];
struct Node{
	int u,v,w;
	int flag;
};
vector <Node> e;
bool cmp(Node X,Node Y){
	return X.w<Y.w;
}
void solve1(){
	int ans=0,cnt=0;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<m;i++){
		if(vis[e[i].u]&&vis[e[i].v]) continue;
		
		ans+=e[i].w;
		vis[e[i].u]++,vis[e[i].v]++;
		cnt++;
		
		if(cnt==n-1) break;
	}
	cout<<ans;
	
	return;
}
void solve2(){
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			e.push_back({i,j,a[j][i],0});
//			for(int l=1;l<=n;l++){
//				if(i==j) continue;
//				e.push_back({i,l,a[j][i]+a[j][l]});
//			}
		}
	}
	int ans=0,cnt=0;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		if(e[i].u==e[i].v) continue;
		if(vis[e[i].u]&&vis[e[i].v]) continue;
		
		ans+=e[i].w;
//		cout<<e[i].w<<"\n";
		vis[e[i].u]=1,vis[e[i].v]=1;
		if(e[i].u<=m&&e[i].v<=m) cnt+=e[i].flag;
		
		if(cnt==n-1) break;
	}
	cout<<ans;
	
	return;	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k; 
	
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[u].push_back({w,v});
		e.push_back({u,v,w,1});
	}
	
	if(k==0){
		solve1();
		return 0;
	}
	
	int flag=1;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]) flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	
	if(flag){
		solve2();
		return 0;
	} 
	
	solve1();
	
	return 0;
} 

//proirity_queue
