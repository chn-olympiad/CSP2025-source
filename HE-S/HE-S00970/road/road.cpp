#include<bits/stdc++.h>
using namespace std;
struct st{
	int id,v,t;
};
vector<st> a[10010];
int n,m,k,dis[10010];
void spfa(int star){
	queue<st> q;
	memset(dis,0x3f,sizeof dis);
	q.push({star,0});
	while(q.size()){
		st find=q.front();
		q.pop();
		for(auto v:a[find.id]){
			if(dis[v.v]>dis[v.id]+v.t){
				dis[v.v]=dis[v.id]+v.t;
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({x,y,z});
		a[y].push_back({y,x,z});
	}
	spfa(1);
	cout<<dis[n];
}
