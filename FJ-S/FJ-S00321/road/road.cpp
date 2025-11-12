#include<iostream>
#include<vector>
#include<fstream>
const int N=1e4+5;
using namespace std;
int n,m,k;
struct edge{
	int v,w;
};
vector<edge> e[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w; cin>>u>>v>>w;
		e[u].push_back(edge{v,w});
		e[v].push_back(edge{u,w});
	}
	for(int i=0;i<k;i++){
		int c; cin>>c;
		for(int i=1;i<=n;i++){
			if(i==c) continue;
			int w; cin>>w; 
			e[c].push_back(edge{i,w});
		}
	}
	return 0;
}
