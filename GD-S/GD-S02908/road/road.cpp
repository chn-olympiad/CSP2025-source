#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 5;
using namespace std;

int n, m, k, f[N], ans, a[15][N], c[N], pe[N];
struct node{
	int u, v, w;
};
vector<node> e;

bool vis[15][N];

int find(int x){
	if(f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

void mer(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b) f[a] = b;
	return;
}

bool cmp(node x, node y){
	return x.w < y.w;
}

void kruskal(){
	sort(e.begin(), e.end(), cmp);
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
	for(auto i: e){
		if(find(i.u) != find(i.v)){
			mer(i.u, i.v);
			ans += i.w;
		}
	}
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({a, b, c});
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(int l = j + 1; l <= n; l++){
				e.push_back({j, l, a[i][j] + a[i][l]});
			}
		}
	}
	kruskal();
	cout << ans;
	return 0;
}
