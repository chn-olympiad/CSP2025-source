#include<bits/stdc++.h>
#define qwq ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

const int N = 1e4 + 20;
const int M = 2e6 + 5;

struct node{
	int u , v , w;
}e[M];

int n , m , k , ans , fa[N] , vis[N] , to[N];
int p[15][N];

bool cmp(const node &lhs , const node &rhs){
	return lhs.w < rhs.w;
}

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

bool uni(int x , int y){
	int u = find(x) , v = find(y);
	if(u == v) return false;
	
	fa[u] = v;
	return true;
}

void solve1(){
	int idx = m , cnt = 0 , r = 0;
	
	for(int i = 1 ; i <= k ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			e[++ idx] = {n + i , j , p[i][j] + p[i][0]};
		}
	}
	sort(e + 1 , e + idx + 1 , cmp);
	
	for(int i = 1 ; i <= idx ; i ++){
		if(uni(e[i].u , e[i].v)){
			if(e[i].u > n && !to[e[i].u]) r ++;
			
			if(e[i].u > n && to[e[i].u] == 1){
				e[i].w -= p[e[i].u - n][0];
			}
			to[e[i].u] = 1;
			ans += e[i].w , cnt ++;
		}
		if(cnt == n + r - 1) break;
	}
	cout << ans;
}

signed main(){             qwq
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1 ; i <= m ; i ++){
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	
	for(int i = 1 ; i <= n + k ; i ++){
		fa[i] = i;
	}
	for(int i = 1 ; i <= k ; i ++){
		for(int j = 0 ; j <= n ; j ++){
			cin >> p[i][j];
		}
		sort(p[i] + 1 , p[i] + 1 + n);
	}
	solve1();
	return 0;
}
