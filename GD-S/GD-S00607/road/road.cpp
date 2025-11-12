#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n,m,k;
long long ans;
int fa[maxn];
int find(int x){return (fa[x]==x)?x:fa[x] = find(fa[x]);}
vector<pair<int,int>>g[maxn];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)fa[i] = i;
	for(int i = 1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({w,v});
		g[v].push_back({w,u});
		q.push({w,{u,v}});
	}
	for(int i = 1,c,w;i<=k;i++){
		cin>>c;
		for(int j = 1;j<=n;j++){
			cin>>w;
			g[i].push_back({w,j});
			g[j].push_back({w,i});
			q.push({w,{i,j}});
		}
	}
	while(q.size()){
		int u = q.top().second.first,v = q.top().second.second,w = q.top().first;
		q.pop();
		int fu = find(u),fv = find(v);
		if(fu==fv)continue;
		fa[fu] = fv;
//		cout<<u<<" "<<v<<'\n';
		ans+=w;
	}
	cout<<ans; 
	
} 
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4

4 4 0
1 2 1
2 3 3
3 4 3
4 5 7
5 2 7
1 4 4
*/
