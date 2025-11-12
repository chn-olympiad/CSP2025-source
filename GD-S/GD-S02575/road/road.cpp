#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int K = 15;

struct Node{
	int id;
	long long d, w;
	Node(int _id, long long _d, long long _w) : id(_id), d(_d), w(_w) {
	} 
	
	bool operator < (const Node &p)const{
		return d > p.d;
	}
};

struct Edge{
	int v;
	long long w;
	Edge(int _v, long long _w) : v(_v), w(_w) {
	}
};

priority_queue<Node> q;
vector<Edge> edges[N + K];
vector<Node> cS;
long long dis[N + K];
bool vis[N + K];
int cnt[K]; //乡村使用次数
int n, m, k; 

long long dj(int s){
	//int fk = 0;
	dis[s] = 0;
	q.push(Node(s, 0, 0));
	while(!q.empty()){
		//fk++;
		Node nowNode = q.top();
		q.pop();
		int nowId = nowNode.id, nowDis = nowNode.d; 
		if(vis[nowId]){
			continue;
		} 
		vis[nowId] = true;
		if(nowId > N){  //乡村 
			cnt[nowId - N]++;
			long long changeCost = 0;
			if(cnt[nowId - N] == 1){
				changeCost = cS[nowId - N].w;
			}
			bool isUsed = false;
			for(int i = 0; i < edges[nowId].size(); i++){
				int v = edges[nowId][i].v; 
				if(dis[nowId] + edges[nowId][i].w + changeCost < dis[v]){
					dis[v] = dis[nowId] + edges[nowId][i].w + changeCost;
					q.push(Node(v, dis[v], 0));
					isUsed = true;
				}
			}
			if(!isUsed){
				cnt[nowId - N]--;
			}
		}else{  //城市 
			for(int i = 0; i < edges[nowId].size(); i++){
				int v = edges[nowId][i].v;
				//cout << dis[nowId] << " " << edges[nowId][i].w << " " << dis[v];
				if(dis[nowId] + edges[nowId][i].w < dis[v] && v <= N){
					dis[v] = dis[nowId] + edges[nowId][i].w; 
					q.push(Node(v, dis[v], 0));
				}else if(dis[nowId] + edges[nowId][i].w <= dis[v] && v > N){
					dis[v] = dis[nowId] + edges[nowId][i].w; 
					q.push(Node(v, dis[v], cS[v - N - 1].w));
				}
			}
		}
	}
	long long ans = INT_MIN;
	for(int i = 1; i <= n; i++){
		//cout << dis << " ";
		ans = max(ans, dis[i]);
	}
	//cout << fk << endl;
	return ans;
}

int main(){
	freopen("road.out", "w", stdout);
	freopen("road.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		edges[u].push_back(Edge(v, w));
		edges[v].push_back(Edge(u, w)); 
	}
	for(int i = 1; i <= k; i++){
		long long c;
		scanf("%lld", &c);
		cS.push_back(Node(N + i, 0, c));
		for(int j = 1; j <= n; j++){
			long long w;
			scanf("%d", &w);
			edges[N + i].push_back(Edge(j, w));
			edges[j].push_back(Edge(N + i, w));
		}
	}
	for(int i = 0; i < N + K; i++) dis[i] = INT_MAX;
//	for(int i = 1; i <= n; i++){
//		cout << dis[i] << " ";
//	}
	long long ans = dj(1);
	printf("%lld", ans);
	
	return 0;
}
