#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e4+5;

int n,m,k;

struct Edge{
	int v,w;
};

vector<Edge> G[N];
bool vis[N];

int ans = 2147483647;
void dfs(int step,int pos,int sum){
    cout << pos <<endl;
	if(step==n){
		ans = min(ans,sum);
	}

	for(Edge e:G[pos]){
		if(!vis[e.v]){
			vis[e.v] = 1;
			dfs(step+1,e.v,sum+e.w);
			vis[e.v] = 0;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}

    vis[1] = 1;
	dfs(1,1,0);

	cout << ans;

	return 0;
}





