#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#define int long long

using namespace std;

constexpr int N = 20005, M = 2000006;
constexpr long long INF = 1e18;

int n, m, k, ans, cs;
int c[15], fa[N];

struct node{
	int u, v, w, id;
};
vector<node> edge;
bitset<N> book;

inline int rd(){
	int w = 0, f = 1; char ch = getchar();
	while(ch < '0' && ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') w = (w << 3) + (w << 1) + (ch ^ 48), ch = getchar();
	return w * f;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

inline bool cmp(node x, node y){
	return x.w < y.w;
}

inline void kru(){
	for (int i = 0; i < edge.size(); i++){
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		if(find(u) != find(v)){
			fa[find(u)] = find(v);
			ans += w;
			if(!book[u]) cs++;
			if(!book[v]) cs++;
			book[u] = book[v] = 1;
		}
		if(cs == n + k) break;
	}
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(), m = rd(), k = rd();
	for (int i = 1; i <= m; i++){
		int u, v, w;
		u = rd(), v = rd(), w = rd();
		edge.emplace_back(node{u, v, w, i});
	}
	for (int i = 1; i <= k; i++){
		int w;
		c[i] = rd();
		for (int j = 1; j <= n; j++){
			w = rd();
			edge.emplace_back(node{i + n, j, w, i + m});
		}
	}
	
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	
	sort(edge.begin(), edge.end(), cmp);
	kru();
	
	cout << ans;
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
