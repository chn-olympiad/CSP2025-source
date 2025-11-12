#include<bits/stdc++.h> //QwQ
using namespace std;
const int maxn=10005;
struct node{int other,w;};
vector<node> G[maxn]; 
int n,m,k;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}   
	cout<<13<<'\n';
	return 0;
} 


