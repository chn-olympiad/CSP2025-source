#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 10;

struct Node{
	int u, v, w;
};

struct Type{
	int c, a[N];
};

int n, m, k, cnt_n, cnt_m;
long long res;
int top[N + 15];
Node g[M + N * 10];
Type town[15];
vector<int> vis[15];

bool cmp(Node a, Node b){
	return a.w < b.w;
}

bool cmp2(Type a, Type b){
	return a.c < b.c;
}

int root(int i){
	while(top[i] != i){
		i = top[i];
	}
	return i;
}

long long solve(){
	long long res = 0;
	for(int i = 1; i <= cnt_n - n; i++){
		vis[i].clear();
	}
	sort(g, g + cnt_m, cmp);
	int cnt = 0;
	for(int i = 1; i <= cnt_n; i++){
		top[i] = i;
	}
	for(int i = 0; i < cnt_m; i++){
		if(cnt >= cnt_n - 1){
			break;
		}
		int u = g[i].u;
		int v = g[i].v;
		top[u] = root(u);
		top[v] = root(v);
		if(top[u] != top[v]){
			cnt++;
			res += g[i].w;
			top[u] = top[v];
			if(u > n){
				vis[u - n].push_back(v);
			}
		}
	}
	return res;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	cnt_n = n;
	cnt_m = m;
	for(int i = 0; i < m; i++){
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	for(int i = 1; i <= k; i++){
		cin >> town[i].c;
		for(int j = 1; j <= n; j++){
			cin >> town[i].a[j];
		}
	}
	sort(town + 1, town + 1 + k, cmp2);
	res = solve();
	for(int i = 1; i <= k; i++){
		cnt_n++;
		for(int j = 1; j <= n; j++){
			g[cnt_m++] = (Node){n + i, j, town[i].a[j]};
		}
		long long ans = solve();
		for(int j = 1; j <= i; j++){
			if(vis[j].size() > 1){
				ans += town[j].c;
			}else{
				if(vis[j].size()){
					ans -= town[j].a[vis[j][0]];
				}
			}
		}
		res = res < ans ? res : ans;
	}
	cout << res << endl;
	return 0;
}
