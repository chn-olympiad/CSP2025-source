#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,s,c[N];
struct edge{
	int to,w;
};
struct node{
	int u,w;
};
bool t[N];
//priority_queue<node,vector<node>> q;
vector<vector<edge>> f;
vector<int> a[15];
void bfs(){
	queue<node> q;
	q.push({1,0});
	t[1]=1;
	while(!q.empty()){
		node x=q.front();
		q.pop();
		u=x.u;
		w=x.w;
		t[u]=1;
		for(auto ed :f[u]){
			if()
		}
		for(auto ed : f[u]){
			if(!t[ed.to]){
				q.push({ed.to,ed.w+w});
			}
		}
		
	}
	
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u].push_back({v,w});
		f[v].push_back({u,w});
	}
	for(int i=1;i<=s;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[j][i];
	}
	return 0;
}
