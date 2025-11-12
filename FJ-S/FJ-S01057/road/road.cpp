#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct edge{
	int u,v,w;
	edge(int U = 0,int V = 0,int W = 0){
		u = U;
		v = V;
		w = W;
	}
}G[1000005],e[110005],tmp[110005];
int n,m,k,E,a[15][10005],c[15],f[10015],s[10015];
long long ans = 0x7fffffffffffffff;
bool cmp(edge x,edge y){
	return x.w < y.w;
}
void initf(int N){
	for(int i = 1;i <= N;i++){
		f[i] = i;
		s[i] = 1;
	}
	return;
}
int qwqf(int v){
	return (f[v]==v?v:qwqf(f[v]));
}
bool qwqu(int u,int v){
	u = qwqf(u);
	v = qwqf(v);
	if(u == v)
		return 0;
	if(s[u] >= s[v]){
		f[v] = u;
		s[u] += s[v];
	}else{
		f[u] = v;
		s[v] += s[u];
	}
	return 1;
}
long long kruskal(int tot){
	initf(n+tot);
	for(int i = 1;i <= E;i++)
		tmp[i] = e[i];
	sort(tmp+1,tmp+E+1,cmp);
	int r = n+tot-1;
	long long sum = 0;
	for(int i = 1;i <= E && r;i++){
		if(qwqu(tmp[i].u,tmp[i].v)){
			sum += tmp[i].w;
			r--;
		}
	}
	return sum;
}
void dfs(int x,int tot,long long sum){
	if(x == k+1){
		ans = min(ans,sum+kruskal(tot));
		return;
	}
	dfs(x+1,tot,sum);
	for(int i = 1;i <= n;i++)
		e[E+i] = edge(n+tot+1,i,a[x][i]);
	E += n;
	dfs(x+1,tot+1,sum+c[x]);
	E -= n;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
		cin >> G[i].u >> G[i].v >> G[i].w;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	initf(n);
	sort(G+1,G+m+1,cmp);
	int r = n-1;
	for(int i = 1;i <= m && r;i++){
		if(qwqu(G[i].u,G[i].v)){
			e[++E] = G[i];
			r--;
		}
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
