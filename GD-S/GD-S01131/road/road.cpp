#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 20;
const int M = 1e6 + 10;

int o[20][N];
bool kk[20];
//À²À²À² À²À² À²À²À²
 
struct node{
	int u, v, w;
	bool operator <(const node &x) const{
		return w > x.w;
	}
};
priority_queue<node> g;


bool cmp(node x, node y){
	return x.w < y.w;
}

int f[N], siz[N];
void init(int n, int k){
	for(int i=1; i<=n + k; i++){
		f[i] = i;
		siz[i] = 1; 
	}
}
int fin(int x){
	if(x == f[x])return x;
	return f[x] = fin(f[x]);
}
void merge(int x, int y){
	if(siz[x] < siz[y])swap(x, y);
	f[y] = x;
	siz[x] += siz[y];
}


signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;cin >>n >> m >> k;
	init(n, k);
	for(int i = 1; i<=m; i++){
		int u ,v, w; cin >> u >> v >> w;
		g.push({u, v, w});
	}

	
	for(int i=1; i<=k; i++){
		int c; cin >> c;
		for(int j =1; j<=n; j++){
			int a; cin >> a;
			g.push({i + n, j, a + c});
			o[i][j] = a;
		}
	}
	
	
	int sum = 0;
	while(g.size()){
		node x = g.top();
		g.pop();
		int u = x.u, v = x.v, w = x.w;
		if(u > n){
			if(kk[u - n] && w != o[u - n][v]) continue;
		}
		u = fin(u), v = fin(v);
		if(u != v){
			merge(u, v);
			sum += w;
			if(x.u > n && kk[x.u - n] == 0){
				kk[x.u - n] = 1;
				for(int i=1; i<=n; i++){
					if(i != v){
						g.push({x.u, i, o[u - n][i]});
					}
				}
			}
		}
		int a = fin(1), l = 0;
		for(int i=2; i<=n; i++){
			if(fin(i) != a) l = 1;
		}
		if(!l) break;
	}
	cout << sum;
	return 0;
}
/*
Æ¯ÁÁµÄ¼Ù¶¯×÷ºÜË§Æø 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
