#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn = 1e5+5; 
int n,m,k;
int via[12][10005];
ll ans,way;

struct e{
	int to;
	int dis;
	int next;
}edge[mn*20];
int head[mn];
int cnt = 0;

struct node{
	int t;
	int dis;
	bool operator<(node x) const{
		return dis > x.dis;
	}
};
priority_queue<node> q;
vector<ll> dist(mn,INT_MAX);

void add(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].dis = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

void del(int cnt,int w){
	edge[cnt].dis = INT_MAX;
}

void disj(int s){
	dist[s] = 0;
	q.push((node){s,0});
	while(!q.empty()){
		node x = q.top();
		q.pop();
		
		for(int i = head[x.t] ; i ; i = edge[i].next){
			int to = edge[i].to;
			int w = edge[i].dis;
			//cout << x.t << ' ' << to << ' ' << w << endl;
			if(w == INT_MAX){
				continue;
			}
			
			if(dist[to] > x.dis + w){
				dist[to] = x.dis + w;
				q.push((node){to,x.dis + w});
				x.dis = dist[to];
				dist[x.t] =x.dis;
				way = dist[to];
				//cout << "way" << way << endl;
			}
		}
	}
}

void build(){
	for(int i = 1 ; i <= k ; i++){
		if(via[k][0] > ans){
			continue;
		}
		int num = 0;
		for(int j = 1 ; j <= n ; j++){
			add(n+i,j,via[i][j]);
			add(j,n+i,via[i][j]);
			num += 2;
		}
		for(int i = 1 ; i <= mn ; i++){
			dist[i] = INT_MAX;
		}
		disj(1);
		way += via[i][0];
		ans = min(ans,way); 
		way -= via[i][0];
		int ncnt = cnt;
		for(int j = 1 ; j <= num ; j++){
			del(ncnt-1,INT_MAX);
			del(ncnt-1,INT_MAX);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1 ; i <= m ; i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> via[i][0];
		for(int j = 1 ; j <= n ; j++){
			cin >> via[i][j];
		}
	}
	ans = INT_MAX;
	disj(1);
	ans = min (way,ans);
	build();
	
	cout << ans << endl;
	
	return 0;
} 
