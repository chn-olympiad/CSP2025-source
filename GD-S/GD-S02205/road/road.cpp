#include<bits/stdc++.h>
using namespace std;

int n, m, k;
long long ans;
int fa[10015], c[15];
int du[15];
vector<int> vec[15];
struct Edge{
	int u, v, w;
}e[1100050];

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
} 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= 10010; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	int top = m;
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> e[++top].w;
			e[top].u = n + i;
			e[top].v = j;
		}
	}
	sort(e + 1, e + top + 1, cmp);
	for(int i = 1; i <= top; i++){
		int fu = find(e[i].u), fv = find(e[i].v);
		if(fu != fv){
			fa[fu] = fv;
			if(fu > n){
				du[fu - n]++;
				vec[fu - n].push_back(e[i].w);
			}
			else if(fv > n){
				du[fv - n]++;
				vec[fv - n].push_back(e[i].w);
			}
			else ans += e[i].w;
		}
	}
	for(int i = 1; i <= k; i++){
		if(du[i] <= 2){
			for(auto v : vec[i]) ans += v;
		}
	}
	cout << ans << "\n";
	return 0;
} 
