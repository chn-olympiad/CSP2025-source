#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;

const int N = 1e6 + 10;
struct node{
	int val, u, v;
};
vector<node> a;
int cnt, c[N];
int fa[N];

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void hb(int x, int y){
	if(fa[x] > fa[y]) fa[y] = fa[x];
	else fa[x] = fa[y];
}
bool cmp(node x, node y){
	return x.val < y.val;
}
signed main(){
	fin("road.in");
	fout("road.out");
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		a.push_back({w, u, v});
	} 
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			int v;
			cin >> v;
			a.push_back({c[i] + v, i, j});
		}
	}
	sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < a.size(); i++){
//		cout << a[i].u << ' ' << a[i].v << ' ' << a[i].val << '\n';
	}
	for(int i = 0; i <= n; i++) fa[i] = i;
	for(int i = 0; i < a.size(); i++){
		auto u = a[i];
		if(find(u.u) == find(u.v)){
			continue;
		}else{
			hb(u.u, u.v);
			cnt += u.val;
//			cout << u.u << ' ' << u.v << ' ' << u.val << '\n';
		}
	}
	cout << cnt;
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

