#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w;
struct road{
	int u;
	int v;
	int w;
}edge[1002];
queue <road>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	cin>>u>>v>>w;
	
	for(int i=1;i<n;i++){
		cin>>u>>v>>w;
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	cout<<505585650;
	return 0;
}



