#include<bits/stdc++.h>
#include<set>
#define int long long
const int N = 1e6 + 5;
int n,m,k,fa[N],a[15][N],c[15];
struct node {
	int u,v,w;
	bool operator < (node o) const {
		return w < o.w;
	}
} e[N];
int find(int x) {
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}
bool query(int u,int v) {
	u = find(u),v = find(v);
	return u == v;
}
void join(int u,int v) {
	u = find(u),v = find(v);
	fa[u] = v;
}
node bei[N * 10];
void build() {
	for(int i = 1; i <= n; i ++) {
		fa[i] = i;
	}
	std::sort(e + 1,e + m + 1);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		if(query(e[i].u,e[i].v)) continue;
		ans += e[i].w;
		join(e[i].u,e[i].v);
	}
	printf("%d\n",ans);
	return;
}
bool f[15],flag;
int build2() {
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		bei[i] = e[i];
	}
	int cnt = m;
	for(int i = 1; i <= k; i ++) {
		if(f[i]) {
			ans += c[i];
			for(int j = 1; j <= n; j ++) {
				bei[++ cnt].u = i + n,bei[cnt].v = j,bei[cnt].w = a[i][j];
			}
		}
	}
	for(int i = 1; i <= n + k; i ++) {
		fa[i] = i;
	}
	std::sort(bei + 1,bei + cnt + 1);
	for(int i = 1; i <= cnt; i ++) {
		if(query(bei[i].u,bei[i].v)) continue;
		ans += bei[i].w;
		join(bei[i].u,bei[i].v);
	}
	return ans;
}

int dfs(int dep) {
	if(dep == k + 1) {
		return build2();
	}
	int ans = dfs(dep + 1);
	f[dep] = 1;
	ans = std::min(dfs(dep + 1),ans);
	f[dep] = 0;
	return ans;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1; i <= m; i ++) {
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i = 1; i <= k; i ++) {
		scanf("%d",c + i);
		flag |= c[i] > 0;
		for(int j = 1; j <= n; j ++) {
			scanf("%d",&a[i][j]);
		}
	}
	if(k == 0) build();
	else if(!flag){
		for(int i = 1;i <= k;i ++){
			f[i] = 1;
		}
		printf("%d\n",build2());
	}
	else {
		printf("%d\n",dfs(1));
	}
}
