#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef pair<int, int> pii;
vector<pair<int, int> > g[N];
int n, m, k;

int mst = 0, root[N];

priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii>> > pq;

void init(){
	for(int i=1;i<=n;++i){
		root[i] = i;
	} 
}

int find(int x){
	if(root[x] == x) return x;
	return root[x] = find(root[x]);
} 

void Union(int x, int y){
	int rootx = find(x);
	int rooty = find(y);
	if(rootx != rooty){
		root[rootx] = rooty;
	}
}

void kruskal(){
	int cnt = n-1;
	while(!pq.empty() && cnt > 0){
		auto edge = pq.top(); pq.pop();
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if(find(u) != find(v)){
			Union(u, v);
			mst += w;
			cnt --;
		} 
	} 
} 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m >> k;
	init();
	for(int i=1;i<=m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		Union(u, v);
		pii temp;
		temp.first = w;
		temp.second = v;
		g[u].push_back(temp);
		temp.second = u;
		g[v].push_back(temp);
		pair<int, pii> temp2;
		temp2.first = w;
		temp2.second.first = u;
		temp2.second.second = v;
		pq.push(temp2);
		
	}//不管乡镇
	
	for(int i=1;i<=k;++i){
		int temp;
		for(int j=1;j<=n+1;++j){
			cin >> temp;
		}
	} 
	kruskal();
	cout << mst << endl;
	return 0;
}