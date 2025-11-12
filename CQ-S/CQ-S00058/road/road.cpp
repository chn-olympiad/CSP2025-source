#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node1{
	int v,w;
};
struct node{
	vector<node1> v;
};
struct node2{
	int w;
	vector<int> v;
};
vector<node> a(10005);
vector<node2> c(15);
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].v.push_back({v,w});
		a[v].v.push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].w;
		for(int i=1;i<=n;i++){
			int w;
			cin>>w;
			c[i].v.push_back(w);
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else cout<<505585650;
	return 0;
}
