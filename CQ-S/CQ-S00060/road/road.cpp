#include<bits/stdc++.h>
using namespace std; 
bool vi[10005];
struct edge{
	int v,w;
};
const int add=15000;
vector<edge>to[20005];
int n,m,k,c[15],ans;
struct point{
	int v,w;
};
bool operator<(point a,point b){
	return a.w>b.w;
}
priority_queue<point>q;
int cnt=1;
void tre(){
	int len=to[1].size();
	for(int i=0;i<len;i++){
		q.push({to[1][i].v,to[1][i].w});
	}vi[1]=1;
	while(q.size()){
		point t=q.top();q.pop();
		if(vi[t.v])continue;
		vi[t.v]=1;ans+=t.w;
		if(t.v<=n)cnt++;
		if(cnt==n)break;
		int len=to[t.v].size();
		for(int i=0;i<len;i++){
			int ve=to[t.v][i].v;
			if(vi[ve]==0){
				q.push({ve,to[t.v][i].w});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		to[u].push_back({v,w});
		to[v].push_back({u,w});
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;cin>>w;
		//	to[i+add].push_back({j,w});
		//	to[j].push_back({i+add,c[i]});
		}
	}
	tre();
	cout<<ans;
	return 0;
}
/*
 4 4 2
1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
*/
