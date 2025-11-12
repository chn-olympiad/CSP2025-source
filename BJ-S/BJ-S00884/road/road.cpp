#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+7;
const int maxm=1e5+7;

struct node{
	int num,fa_edge;
	vector<int> edge_connected,cheapest_node[15];//cheapest_node[k][i]代表切掉边edge_connected[i]后掉落的子树中在第k次城镇化中修路最便宜的节点
}city[maxn];

struct Edge{
	int u,v,w;
}edge[maxm];

bool operator< (const Edge &x,const Edge &y){
	return x.w < y.w;
}

int n,m,k,cost;
vector<int> edge_chosen;
int bcj[maxn];

int findfa(int x){
	if(bcj[x] == x)return x;
	return findfa(bcj[x]);
}

void init(){
	for(int i=1;i<=n;i++)bcj[i]=i;
	return;
}
//void dfs(int cur){
//
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	init();
	for(int i=1;i<=m;i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	}
	sort(edge+1,edge+m+1);
	for(int i=0,j=1;i<n-1;j++){
		if(findfa(edge[j].u)!=findfa(edge[j].v)){
			bcj[findfa(edge[j].u)] = bcj[findfa(edge[j].v)];
			cost += edge[j].w;
			edge_chosen.push_back(j);
			city[edge[j].u].edge_connected.push_back(j);
			city[edge[j].v].edge_connected.push_back(j);
			i++;
		}
	}
	cout << cost;
	return 0;
}
