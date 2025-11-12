#include<bits/stdc++.h> 
using namespace std;
struct node{
	int u,v,c;
}road[1000100];
bool vis[100015];
int n,m,k,idx,id,ans = 1e9;
bool temp[1000100];
bool check(){
	for(int i = 1;i <= n;++i)
		if(!vis[i])
			return vis[i];
	return true;
}
void dfs(int step,int cost){
	if(step == m){
		if(check()) ans = min(ans,cost);
		return;
	}
	dfs(step + 1,cost);
	vis[road[step].u] = true;
	vis[road[step].v] = true;
	dfs(step + 1,cost + road[step].c);
	vis[road[step].u] = false;
	vis[road[step].v] = false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k; idx = 1;
	for(int i = 1;i <= m;++i) cin >> road[i].u >> road[i].v >> road[i].c;
	for(int i = 1;i <= k;++i){
		int minus; cin >> minus;
		for(int j = 1;j <= n;++j){
			int delta; cin >> delta;
			road[m + idx].u = n + id;
			road[m + idx].v = j;
			road[m + idx].c = delta + minus;
			idx++; 
		}
		id++;
	}
	dfs(1,0);
	cout << ans << "\n";
	return 0;
}
