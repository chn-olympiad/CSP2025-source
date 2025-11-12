#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,w;
};
vector<edge>e[10005];
priority_queue<int,vector<int>,greater<int>>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			e[u].push_back({v,w});
//			e[v].push_back({u,w});
			q.push(w);
		}
		int sum=0;
		for(int i=1;i<m;i++){
			sum+=q.top();
			q.pop();
		}
		cout<<sum<<'\n';
		exit(0);
	}else{
		cout<<0<<'\n';
		exit(0);
	}
	return 0;
}
