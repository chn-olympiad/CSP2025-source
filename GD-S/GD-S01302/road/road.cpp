#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 15;
const int M = 1e6 + 15;
int n,m,k,to[M * 2],h[M * 2],nxt[M * 2],val[M * 2],tot,cnt;
int a[25][N],c[N],viss[25],rom;
ll ans,dis[N],sum,tmp;
bool vis[N];
void add(int u,int v,int w){
	to[++ cnt] = v;
	nxt[cnt] = h[u];
	h[u] = cnt;
	val[cnt] = w;
	return ;
}
struct qq{
	int v,fa;
	ll w;
	friend bool operator <(qq x,qq y){
		return x.w > y.w;
	}
};
void prim(int s){
	for(int i = 1;i <= n;i ++){
		dis[i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<qq> q;
	q.push({s,0,0});
	dis[s] = 0;
	cnt = 0,sum = 0;
	for(int i = 1;i <= rom;i ++){
		sum += c[i];
	}
	while(!q.empty()){
		int u = q.top().v,w = q.top().w,fa = q.top().fa;
		q.pop();
		if(vis[u]){
			continue;
		} 
		vis[u] = 1;
		cnt ++;
		sum += dis[u];
		for(int i = h[u];i;i = nxt[i]){
			if(dis[to[i]] > (ll)(dis[u] + val[i])){
				dis[to[i]] = dis[u] + val[i];
				q.push({to[i],u,dis[to[i]]});
			}
		}
		for(int i = 1;i <= n;i ++){
			if(rom == 0 || i == u){
				continue;
			}
			tmp = 1e18;
			for(int j = 1;j <= rom;j ++){
				tmp = min((ll)(a[j][u] + a[j][i]),tmp);
			}
			if(dis[i] > tmp){
				dis[i] = tmp;
				q.push({i,u,dis[i]});
			}
		}
	}
	if(cnt == n){
		ans = min(ans,sum);
	}
	return ;
}
int main(){
//	freopen("road1.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1,u,v,w;i <= n;i ++){
		cin >> u >> v >> w;
		add(u,v,w);
	}
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	ans = 1e18;
	for(int i = 0;i <= k;i ++){
		rom = i;
		for(int j = 1;j <= n;j ++){
			prim(j);
		}
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
