#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e5+10;
typedef long long ll;
vector<pair<int,ll>>adj[N];
bitset<N>vis;
ll dis[N];
struct node{
	int u;
	ll w;
	bool operator>(const node&o)const{
		return w<o.w;
	}
};
constexpr ll INF=1e18;
void dijkstra(){
	int s=1;
	priority_queue<node,vector<node>,greater<node>>q;
	q.push({s,0});
	for(int i=0;i<N;++i) dis[i]=INF;
	dis[s]=0;
	while(!q.empty()){
		auto cur=q.top();
		q.pop();
		if(vis[cur.u]) continue;
		vis[cur.u]=1;
		for(int i=0;i<adj[cur.u].size();++i){
			int to=adj[cur.u][i].first;
			ll w=adj[cur.u][i].second;
			if(dis[cur.u]+w<dis[to]){
				dis[to]=dis[cur.u]+w;
				q.push({to,dis[to]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("ans.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dijkstra();
	ll ans=0;
	for(int i=1;i<=n;++i) if(dis[i]!=INF) ans=max(ans,dis[i]);
//	for(int i=1;i<=n;++i) cout<<dis[i]<<" ";
//	cout<<endl;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
3 3 0
1 2 9
1 3 7
2 3 1

*/
















/*

check_config_gen.bat

@echo off
setlocal enabledelayedexpansion

set "problems="

for %%a in (1 2 3 4) do (
    set /p "p%%a=Enter problem name %%a: "
    set "problems=!problems! !p%%a!"
)

(
echo {
echo     "md5_check": [
echo         {
echo             "name": "csps.zip",
echo             "md5": "fed5a2e2b397fc303476cd0185c11d65"
echo         }
echo     ],
echo     "root_path": "E:\\",
echo     "regex": "^GD-S\\d{5}$",
echo     "problems": [
) > "E:\checker.cfg.json"

set /a count=0
for %%a in (%problems%) do (
    set /a count+=1
    if !count! lss 4 (
        set "comma=,"
    ) else (
        set "comma="
    )
    (
    echo         {
    echo             "name": "%%a",
    echo             "regex": "^%%a\\\\%%a\\.(cpp|c|pas)$"
    echo         }!comma!
    ) >> "E:\checker.cfg.json"
)

(
echo     ],
echo     "start_time": "2025-11-01T14:30:00+08:00",
echo     "end_time": "2025-11-01T18:30:00+08:00",
echo     "size_limit_kb": 100
echo }
) >> "E:\checker.cfg.json"

echo Created E:\checker.cfg.json
pause


*/
