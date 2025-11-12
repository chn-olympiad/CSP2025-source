#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, k ;
struct Edge{
	ll next, to, weight;
};
ll head[1000005];
bool visit[1000005];
ll cnt = 1;
Edge road[1000005];
struct Node{
	ll hao;
	ll dist;
	//没招了， 重载运算符忘记了， 调试了半小时
	//随便改居然能运行了吗会赢吗 -16：37 
	bool operator<(const Node& x) const
    { return dist > x.dist;}
};
ll dist[1000005];
ll ans = 0;
void addedge(ll u, ll v, ll w){
	road[cnt].to = v;
	road[cnt].next = head[u];
	road[cnt].weight = w;
	head[u] = cnt;
	cnt++;
}
ll u, v, w, use;
void dijistra(int stratnode){
	priority_queue<Node, vector<Node>>pq;//小根堆 
	pq.push({stratnode, 0}); 
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		ll u = now.hao;
		if(visit[u]){
			continue;
		}
		visit[u] = true;
		for(int i = head[u]; i>0; i=road[i].next){
			ll v = road[i].to;
			dist[v] = min(dist[v], dist[u] + road[i].weight);
			pq.push({v, dist[v]});
		}
	}
}
int main(){
	freopen("road.in", "r" , stdin);
	cin >> n >> m >> k;
	for(int i = 0 ; i<m ; i++){
		cin >> u  >> v >> w;
		addedge(u, v, w);
		addedge(v, u ,w);
	}
	for(int i = n+1; i<=k+n ; i++){
		cin >> use >> w ;
		addedge(i, 1 , w+use);
		addedge(1, i , w+use);
		for(int j = 2; j<=n ; j++){
			cin >> w;
			addedge(i, j , w);
			addedge(j, i , w);
		}
	}
	for(int i = 2; i<=n+k ; i++){
		dist[i] = 1e12;
	}
	dijistra(1);
	for(int i = 1; i<=n; i++){
		ans = max(ans,dist[i]);
	} 
	cout << ans;
	freopen("road.out", "w" , stdout);
	return 0;
}
//16：58 怎么死循环了？ 
//17: 02 少了visit 怎么写来着 ？ 
//17: 12 输出又错了...
//17: 17 ?????????
//可是自己造的样例过了 
//4 4 0
//1 3 5
//1 2 3
//2 3 1
//3 4 4 
//dijistra好像做不出来 ，破防了 
//.............. 
