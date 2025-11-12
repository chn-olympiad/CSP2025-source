#include <iostream>
#include <vector>
#include <queue>

using i64 = long long;

const int N = 1e4 + 100, M = 2e6 + 5;

int n, m, k;
struct node{
	int u, w;
};
std::vector<node> G[N];
int vis[N], dis[N];
int c[N];
int cnt = 0;
i64 ans = 1e18;
struct cmp{
	bool operator () (const node x, const node y){
		return x.w > y.w;
	}
};

i64 Prim(int state){
	std::priority_queue<node, std::vector<node>, cmp> Q;
	for(int i = 1; i <= n + k; ++i){
        vis[i] = 0;
        dis[i] = 1e9 +7;
	}
	Q.push(node{1, 0});
	i64 ret = 0;
	int ex = 0, num = 0;
	for(int i = 1; i <= k; ++i){
		if((state & (1 << (i - 1))) != 0){
			ret += c[i];
			++ex;
		}
	}
	while(!Q.empty()){
        ++cnt;
		node cur = Q.top();
		Q.pop();
		if(vis[cur.u]){
			continue;
		}
		vis[cur.u] = 1;
		++num;
        ret += cur.w;
		if(num == ex + n){
            break;
		}
		if(ret > ans){
            break;
		}
		for(int i = 0; i < G[cur.u].size(); ++i){
			int v = G[cur.u][i].u, w = G[cur.u][i].w;
			if(v > n && (state & (1 << (v - 1 - n))) == 0){
				continue;
			}
			if(vis[v]){
				continue;
			}
			if(dis[v] < w){
                continue;
			}
            ++cnt;
			Q.push(node{v, w});
			dis[v] = w;
		}
	}
	return ret;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		std::cin >> u >> v >> w;
		G[u].push_back(node{v, w});
		G[v].push_back(node{u, w});
	}

	for(int i = 1; i <= k; ++i){
		int val;
		std::cin >> c[i];
		for(int j = 1; j <= n; ++j){
			std::cin >> val;
			G[i + n].push_back(node{j, val});
			G[j].push_back(node{i + n, val});
		}
	}

	for(int i = 0; i < 1 << k ; ++i){
		ans = std::min(ans, Prim(i));
	}
	std::cout << ans;
	return 0;
}
