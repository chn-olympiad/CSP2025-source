#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,toltalans = 0x3f3f3f3f;
struct vide{
	int v,far;
};
struct side{
	int u,v,far;
};
vector<vide> G[100005];
vector<int> oute[100005];
side ine[100005];
int f[100005],c[100005],afre[15][100005],used[15];
int find(int x){
	if (f[x] == x) return x; 
	return f[x] = find(f[x]);
}void merge(int x,int y){
	f[find(x)] = find(y);
}
bool cmp(side a,side b){
	return a.far < b.far;
}
int kruskal(int n){
	int ans = 0;
	for (int i = 0;i < 10005;i++){
		f[i] = i;
		oute[i].clear();
	}
	sort(ine+1,ine+n+1,cmp);
	for (int i = 1;i <= n;i++){
		int u = ine[i].u;
		int v = ine[i].v;
		if (find(u) == find(v)) continue;
		merge(u,v);
		//cout << u << "<=>" << v << endl;
		ans += ine[i].far;
		oute[u].push_back(v);
		oute[v].push_back(u);
	}
	return ans;
}int zchw(){
	memset(ine,0,sizeof(ine));
	int ans = 0,ini = 1;
	for (int i = 1;i <= n;i++){
		for (int j = 0;j < G[i].size();j++){
			int v = G[i][j].v;
			int far = G[i][j].far;
			ine[ini++] = side{i,v,far};
		}
	}
	for (int i = 1;i <= k;i++){
		if(used[i] == 1){
			ans += c[i];
			for (int j = 1;j <= n;j++){
				ine[ini++] = side{i+n,j,afre[i][j]};
			}
		}
	}
	return kruskal(ini)+ans;
}void sefr(int u){
	if (u == 0){
		toltalans = min(toltalans,zchw());
//		for (int i = 1;i <= k;i++){
//			cout << used[i];
//		}cout << " " << toltalans << endl;
		return;
	}
	used[u] = 1;
	sefr(u-1);
	used[u] = 2;
	sefr(u-1);
	used[u] = 0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		G[u].push_back(vide{v,w});
		ine[i] = side{u,v,w};
	}
	if (k == 0){
		cout << kruskal(m);
		return 0;
	}
//	for (int i = 1;i <= n;i++){
//		for (int j = 0;j < oute[i].size();j++){
//			cout << i << "->" << oute[i][j] << endl;
//		} 
//	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++){
			cin >> afre[i][j];
		}
//		int sum = 0;
//		for (int j = 1;j <= n;j++){
//			int ddj = 0-afre[j];
//			for (int k = 0;k < i.size();k++){
//			    if (!oute[j][k] || sate[j][k]) continue;
//			    ddj += oute[j][k];
//			    sate[j][k] = false;
//			}
//		}
	}
	sefr(k);
	cout << toltalans << endl;
}
