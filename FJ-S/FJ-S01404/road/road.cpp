#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,int> > e[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	q.push(1);
	while(!q.empty()){
		int x=q.front;
		q.pop();
		for(auto it:e[x]){
			
		}
	}
	return 0;
} 
