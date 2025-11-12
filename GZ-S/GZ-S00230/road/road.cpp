//GZ-S00230  遵义市第四中学 李星宸 

#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
long long ans;
long long goal;
long long cnt;
long long fa[100000];
long long vis[20];
long long sum[20];
long long cost[15][100000];

struct node{
	long long u;
	long long v;
	long long w;
	long long opt;//为1为加边，为0为加点 
	bool operator < (const node &er_mao)const{
		return er_mao.w < w;
	}
};

priority_queue <node> q;

long long _find(long long x){
	if(x == fa[x]){
		return x;
	}
	return fa[x] = _find(fa[x]);
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
			
	cin >> n >> m >> k;
	
	goal = n;
	for(int i = 1; i <= n + k; i++){
		fa[i] = i;
	}
	long long u, v , w;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		q.push({u, v, w, 1});
	}
	for(int i = 1; i <= k; i++){
		cin >> sum[i];
		for(int j = 1; j <= n; j++){
			cin >> cost[i][j];
		}
		q.push({i, 0, sum[i], 0});
	}
	node t;
	long long fa_u, fa_v;
	cnt = 1;
	while(!q.empty()){
		if(cnt == goal){
			break;
		}
		t = q.top();
		q.pop();
		if(t.opt == 1){
			fa_u = _find(t.u);
			fa_v = _find(t.v);
			if(fa_u == fa_v){
				continue;
			}
			fa[fa_v] = fa_u;
			ans += t.w;
			cnt++;
			if(t.u > n){
				vis[t.u - n]++;
				sum[t.u - n] += t.w; 
			}
		}else{
			ans += t.w;
			vis[t.u]++;
			goal++;
			for(int i = 1; i <= n; i++){
				q.push({t.u + n, i, cost[t.u][i], 1});
			}
		}
	}
	for(int i = 1; i <= k; i++){
		if(vis[i] == 1 || vis[i] == 2){
			ans -= sum[i];
		}
	}
	cout << ans;
	
	return 0;
}
