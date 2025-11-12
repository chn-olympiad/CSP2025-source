#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
int n, m, k;
int fa[maxn], size[maxn];
map<pair<int, int>, int>ma;
priority_queue<pair<int , int>>q;
int e[maxm][3];
void init(){
	for(int i = 1 ; i < maxn ; i++){
		fa[i] = i;
		size[i] = 1;
	}
}
int find(int x){
	if(fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}
void plu(int x, int y){
	if(size[x] < size[y])swap(x, y);
	fa[y] = fa[x];
	size[x] += size[y];
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[i][0] = u;
		e[i][1] = v;
		e[i][2] = w;
		ma[make_pair(v, u)] = w;
		ma[make_pair(u, v)] = w;
		q.push(make_pair(-w, i));
	}
	int sum = 0;
	while(!q.empty()){
		pair<int ,int >tmp = q.top();
		q.pop();
		int w = -tmp.first;
		int u = e[tmp.second][0];
		int v = e[tmp.second][1];
		if(find(u) == find(v)){
			continue;
		}
		plu(u, v);
		sum += w;
	}
	cout << sum << endl;
	return 0;
	return 0;
}
