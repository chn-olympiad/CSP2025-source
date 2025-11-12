#include <bits/stdc++.h>
using namespace std;

namespace solve{

typedef long long LL;
const LL INF = 4e18;

vector< vector<LL> > ws;
struct Edge{
	int u, v;
	friend bool operator <(Edge& a, Edge& b){
		return ws[a.u][a.v] < ws[b.u][b.v];
	}
};
//void Dijkstra(){
//}

void main(){
	int n, m, k;
	cin >> n >> m >> k;
	ws = vector< vector<LL> >(n+1, vector<LL>(n+1, INF));
	vector<Edge> edges;
//	map< pair<int,int>, int > ws;
//	map< int, int > tags;
	for (int i=1;i<=n;i++){
		int u, v;
		LL w;
		cin >> u >> v >> w;
		edges.push_back((Edge){u,v});
//		ws[{u,v}] = w;
		ws[u][v] = w;
		ws[v][u] = w;
	}
	while(k--){
		LL a; vector<LL> w(n+1);
		cin >> a;
		for (int i=1;i<=n;i++) cin >> w[i];
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (a+w[i]+w[j] < ws[i][j]){
					edges.push_back((Edge){i,j});
					ws[i][j] = a+w[i]+w[j];
					ws[j][i] = ws[i][j];
				}
			}
		}
	}
	sort(edges.begin(), edges.end());
//	for (Edge edge : edges){
//		cout<<edge.u<<" "<<edge.v<<" "<<ws[edge.u][edge.v]<<"\n";
//	}
//	vector<bool> mark(n+1, 0);
	vector<int> fa(n+1, 0);
	LL ans = 0;
//	int Count = 0;
	for (Edge edge : edges){
		int fau = edge.u, fav = edge.v;
		while (fa[fau]){
			fau = fa[fau];
		}
		while (fa[fav]){
			fav = fa[fav];
		}
		if (fau == fav) continue;
		else{
			ans += ws[edge.u][edge.v];
//			cout <<edge.u<<" "<<edge.v<<" "<< ans << "\n";
//			Count++;
//			if (Count == n-1) break;
			fa[fau] = fav;
		}
//		if (mark[edge.u]){
//			mark[edge.v] = true;
//			int fau, fav;
//			fa[edge.v] = fa[edge.u];
//			Count++;
//		} else if (mark[edge.v]){
//			mark[edge.u] = true;
//			fa[edge.u] = fa[edge.v];
//		} else{
//			mark[edge.u] = true;
//			mark[edge.v] = true;
//			fa[edge.v];
//		}
	}
	cout << ans;
}

}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve::main();
	return 0;
}
