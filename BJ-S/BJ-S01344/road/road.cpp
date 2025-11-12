#include<bits/stdc++.h>
using namespace std;

const int N = 3e7;
long long ans;
struct node{
	int u,v,w;
};
node G[N];
int can[1200][20];
int tot;
int n,m,k;
int fa[N];
int vis[100];
int daijia[100];
int ret[20];

void dfs(int now){
	if(now > k){
		tot++;
		for(int i = 1;i <= k;i++){
			can[tot][i] = ret[i];
		}
		return;
	}
	ret[now] = 1;
	dfs(now + 1);
	ret[now] = 0;
	dfs(now + 1);
}

bool cmp(node a,node b){
	return a.w < b.w;
}

int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> G[i].u >> G[i].v >> G[i].w;
	}
	sort(G + 1,G + m + 1,cmp);
	for(int i = 1;i <= m;i++){
		fa[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int u = G[i].u;
		int v = G[i].v;
		int w = G[i].w;
		int fu = find(u);
		int fv = find(v);
		if(fu != fv){
			fa[fu] = fv;
			ans += w;
		}
	}	
	cout << ans;
	return 0;
}
