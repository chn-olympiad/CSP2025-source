#include <iostream>
#include <algorithm>


using namespace std;
const int N=1e6+10;
int n,m,k;
int cnt=0;
int h[N];
struct edge{
	int to;
	int w;
	int nxt;
	
};
edge e[N];
void addedge(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=h[u];
	h[u]=cnt; 
}

bool vis[N];

void solve(){
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		
	}
	return;
}

int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout); 
	solve();
	return 0;
} 
