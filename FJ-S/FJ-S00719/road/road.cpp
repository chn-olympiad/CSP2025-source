#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+10;
const int INF = 0x3f3f3f3f;
int n,m,k,ans=0x3f3f3f3f;
struct ac{
	int v,w;
};
inline bool operator<(ac x,ac y){
	return x.w>y.w;
}
vector <ac> to[N];
priority_queue<ac> q;
bool vis[N];
int dis[N];
void dfs(int sum,int num,int now){
	if(sum==n){
		//cout << ans << endl;
		ans = min(ans,num);
		return;
	}
		for(ac r : to[now]){
			if(!vis[r.v]){
				//cout << r.v << ":" << r.w << endl;
				vis[r.v] = true;
				if(r.v<=n){
					dfs(sum+1,num+r.w,r.v);
				}
				else dfs(sum,num+r.w,r.v);
				vis[r.v] = false;
			}
		}
}
//void bfs(int now){
//	memset(dis,0x3f3f,sizeof dis);
//	memset(vis,0,sizeof vis);
//	for(ac r : to[1]){
//		q.push({r.v,dis[r.v]=r.w});
//	}
//	vis[1] = true;
//	while(!q.empty()){
//		int i = q.top().v;
//		for(ac t : to[i]){
//			if(!vis[i]) q.push({t.v,dis[t.v]=min(t.w,dis[t.v]}));
//		}
//		vis[i] = true;
//	}
//	for(int i=1;i<=n+k;i++){
//		if(dis[i]!=0x3f3f) ans+=dis[i];
//	}
//}
//void dij(int s){
//	memset(dis,0,sizeof dis);
//	memset(vis,0,sizeof vis);
//	q.push({s,dis[s]=0});
//	while(!q.empty()){
//		int i = q.top().v;
//		q.pop();
//		if(vis[i]) continue;
//		vis[i] = 1;
//		for(ac r : to[i]){
//			if(dis[r.v]>dis[i]+r.w){
//				q.push({r.v,dis[r.v]=dis[i]+r.w});
//				ans += r.w;
//			}
//		}
//	}
//}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		ac temp;
		temp.v = v;
		temp.w = w;
		to[u].push_back(temp);
		temp.v = u;
		to[v].push_back(temp);
	}
	for(int i=n+1;i<=k+n+1;i++){
		int c;
		cin >> c;
		for(int j=1;j<=n;j++){
			int w;
			cin >> w;
			ac temp;
			temp.w = w+c;
			temp.v = j;
			to[i].push_back(temp);
			temp.v = i;
			temp.w = w;
			to[j].push_back(temp);
		}
	}
//	dij(1);
//	for(int i=1;i<=n;i++){
//		ans += dis[i];
//		cout << dis[i] << " ";
//	}
//	bfs(1);
	vis[1] = true;
	dfs(1,0,1);
	cout << ans;
	return 0;
}// I love love u ccf,please give me more score,I wish i can join in noip,please
