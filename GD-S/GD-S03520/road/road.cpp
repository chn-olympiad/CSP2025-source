#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct L{
	int w,v;
	bool operator (L p , L q) const{
		return p.w<q.w;
	}
};

vector<L> g[10002];
int a[12][10002];
priority_queue<L,vector<L> ,greater<L>> b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
	}
	L x;
	x.w=1,x.v=999;
	L y;
	y.w=999,y.v=1;
	b.push(y);
	b.push(x);
	cout<<b.empty();
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int z=0;z<1024;z++){
		
	}
	return 0;
}
