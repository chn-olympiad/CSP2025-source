#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e4 + 10;
const int M = 4e6 + 10;
int n,m,k,u,v,w,a[20][N],idx,fa[N];
struct node{
	int u,v,w;
}h[M];
void add(int u,int v,int w){
	idx++,h[idx].u = u,h[idx].v = v,h[idx].w = w;
}
int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
bool cmp(node a,node b){
	return a.w < b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		add(u,v,w);
	}
	for(int i = 1;i <= n;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= k;i++){
		vector <int> g;
		for(int j = 0;j <= n;j++){
			cin >> a[i][j];
			if(j == 0){
				continue;
			}
			if(a[i][j] == 0){
				g.push_back(j);
			}
		}
		for(int j = 0;j < g.size();j++){
			for(int p = 1;p <= n;p++){
				add(g[j],p,a[i][p]);
			}
		}
	}
	sort(h + 1,h + idx + 1,cmp);
	int sum = 0,ans = 0;
	for(int i = 1;i <= idx;i++){
		if(sum == n - 1){
			break;
		}
		int x = h[i].u,y = h[i].v,z = h[i].w;
		if(find(x) != find(y)){
			fa[find(x)] = find(y);
			sum++,ans += z;
		}
	}
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
