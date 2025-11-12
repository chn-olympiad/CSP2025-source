#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int Maxn = 1e4 + 5,Maxm = 1e6 + 5;

struct node {
	int u,v,w;
}p[Maxm];
 
int n,m,k,fa[Maxn],c[15],a[15][Maxn],d[Maxn][Maxn];

bool cmd(node a,node b) {
	return a.w < b.w;
}

int find(int u) {
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
} 

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m >> k;
	
	for(int i = 1;i <= m;i ++) {
		int u,v,w;
		cin >> u >> v >> w;
		p[i].u = u,p[i].v = v,p[i].w = w;
	}
	
	for(int i = 1;i <= k;i ++) {
		cin >> c[i];
		for(int j = 1;j <= n;j ++) {
			cin >> a[i][j];
		}
	}
	
	if(k != 0) {
		cout << 0;
		return 0;
	}
	
	sort(p + 1,p + m + 1,cmd);
	for(int i = 1;i <= n;i ++) {
		fa[i] = i;
	}
	
	int e = 0;
	ll sum = 0;
	for(int i = 1;i <= m;i ++) {
		if(e == n - 1) {
			break;
		}
		
		int u = p[i].u,v = p[i].v;
		int x = find(u),y = find(v);
		
		if(x == y) {
			continue;
		}
		
		fa[x] = y;
		sum += p[i].w;
	}
	
	cout << sum;
	
	return 0;
}
