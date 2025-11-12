#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct ll N=1e4+10,M=1e6+20;
struct aa{ll to,w;};
struct node{
	ll u,d;
	bool friend operator<(node x,node y){
		return x.d>y.d;
	}
};
ll n,m,k,ans,v[N+100];
priority_queue<node> q;
vector<aa> a[N];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		a[n+k+1].push_back({n+i,x});
		for(int j=1;j<=n;j++){
			int y;
			cin>>y;
			a[n+i].push_back({j,y});
		}
	}
	q.push({1,0});
	while(!q.empty()){
		node s=q.top();q.pop();
		if(v[s.u]) continue;
		v[s.u]=1;
		ans+=s.d;
		
	}
	return 0;
}
