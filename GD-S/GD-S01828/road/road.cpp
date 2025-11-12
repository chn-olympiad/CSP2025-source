#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
vector<pair<int,int>> G[100010];
bool vis[1000010];
int ans = 0;
int n,m,k;
void pim(){
	for(int i = 1;i <= n;i ++)vis[i] = 1;
	que.push({0,1});
	while(!que.empty()){
		int V = que.top().second;
		if(vis[V] == 0)continue;
		vis[V] = 0;
		ans += que.top().first;
		que.pop();
		cout << V << ' ';
		for(auto v : G[V]){
			if(vis[v.first]){
				cout << v.first;
				que.push({v.second,v.first});
			}
		}
		cout << endl;
	}
	return ;
}
int main(){
	cin >> n >> m >> k;
	int x,y,z;
	for(int i = 1;i <= m;i ++){
		cin >> x >> y >> z;
		G[x].push_back({y,z});
		G[y].push_back({x,z});
	}
	pim();
	cout << ans;
	return 0;
}

