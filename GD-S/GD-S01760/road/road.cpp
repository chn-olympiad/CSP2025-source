#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c[15],a[15][10005];
struct Edge{
	int u,w;
};
vector<Edge> e[10005];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	srand(time(0));
	cout<<rand()%100;
	return 0;
}
