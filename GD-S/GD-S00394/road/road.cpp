#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 10005
using namespace std;
vector<int> g[N];
int vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= k; i++){
		int c;
		cin>>c;
		for(int j = 1; j <= n; j++){
			
		}
	}
	
	
	return 0;
} 
