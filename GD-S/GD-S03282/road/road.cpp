#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[10001],res=0x3f3f3f3f;
struct node{
	int x,w;
};
vector<node>g[10001];
map<pair<int,int>,int>mp;
bool v[100001];
void dfs(int x,int s,int p){
	if(s>=res)return; 
//	cout<<x<<' '<<s<<' '<<p<<'\n';
	if(!v[x])p++;
	v[x]=1;
	if(p==n){
		d[x]=min(d[x],s);
		res=min(res,d[x]);
//		for(int i=0;i<q.size();i++){
//			cout<<q[i]<<' '; 
//		} 
//		cout<<" end\n"; 
		return;
	}
//	if(d[x]<=s)return;
//	d[x]=s; 
	for(int i=0;i<(int)g[x].size();i++){
		mp[{x,g[x][i].x}]++;
		if(mp[{x,g[x][i].x}]==2)continue;
//		q.push_back(g[x][i].x); 
		dfs(g[x][i].x,s+g[x][i].w,p);
//		q.pop_back(); 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	while(k--){
		int c,w;
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>w; 
			g[c].push_back({i,w});
			g[i].push_back({c,w}); 
		} 
	} 
//	for(int i=1;i<=n;i++){
//		cout<<i<<':';
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].x<<' ';
//		}
//		cout<<'\n';
//	} 
//	queue<node>q;
//	q.push({1,0});
	
	memset(d,0x3f,sizeof(d));
	v[1]=1;
	dfs(1,0,1); 
//	while(q.size()){
//		node t=q.front();
//		q.pop();
//		if(d[t.x]<=t.w)continue;
//		d[t.x]=t.w;
//		for(auto e:g[t.x]){
//			q.push({e.x,t.w+e.w});
//		}
//	}
	cout<<res<<'\n';
	return 0;
}
