#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	bool operator<(node y)const{
		return w<y.w;
	}
};
vector<node> a[10005];
deque<int>b;
priority_queue<node>pq;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});a[y].push_back({x,z});
	}
	b.push_back(1);
	for(int i=0;i<a[1].size();i++){
		pq.push({a[1][i].v,a[1][i].w});
	}
	int sum=0;
	while(pq.size()){
		node p=pq.top();
		for(auto it:a[p.v]){
			int mi=1e9,f=1;
			for(int j:b){
				if(it.v==j){
					f=0;
					break;
				}
				mi=min(mi,a[j][it.v].w);
			}
			if(f){
				b.push_back(it.v);
				sum+=mi;
			}
		}
	}
	cout<<sum;
	return 0;
}
