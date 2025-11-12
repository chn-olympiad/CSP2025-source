#include <bits./stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10 , M = 1e4 + 10;
const int inf = 0x3f3f3f3f;

int read(){
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} 
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int n , m , k , tot = 0 , dis[N] , p[M] , cnt[11] , d[11];
ll ans = 0;
struct node{
	int pos , w , id;
};
vector<node> e[N];
bitset<N> vis;

void prim(){
	memset(dis , inf , sizeof(dis));
	dis[1] = 0;
	
	for(int i = 1; i <= n; i++){
		int u = 0;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && dis[u] > dis[j]) u = j;
		if(u == 0) break;
		vis[u] = 1 , ans += dis[u];
		
		for(int i = 0; i < e[u].size(); i++){
			int v = e[u][i].pos , w = e[u][i].w , id = e[u][i].id;
			if(vis[v]) continue;
			if(dis[v] > w)
				dis[v] = w , cnt[id]++; 
		}
	}
} 

int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	n = read() , m = read() , k = read();
	for(int i = 1; i <= m; i++){
		int u = read() , v = read() , w = read();
		e[u].push_back({v , w , 0}); 
		e[v].push_back({u , w , 0});
	}
	for(int i = 1; i <= k; i++){
		d[i] = read();
		for(int j = 1; j <= n; j++){
			p[j] = read();
		}
		for(int u = 1; u <= n; u++){
			for(int v = 1; v <= n; v++){
				if(u == v) continue;
				e[u].push_back({v , p[u] + p[v] + d[i] , i});
				e[v].push_back({u , p[u] + p[v] + d[i] , i});
			}
		}
	}
	prim();
	cout << ans << endl;
	return 0;
} 
