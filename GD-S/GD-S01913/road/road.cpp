#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+20, M = 1e6+1e5+9;
int n, m, k, c[15], a[15][N], p[N], f[N], sum, ans = 0x3f3f3f3f3f3f3f3f, fe[M];
struct Edge{
	int u, v, w;
}e[M];
vector<Edge> e1;
bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
int get(int x){
	if(p[x] == x){
		return x;
	}
	return p[x] = get(p[x]);
}
void kruskal(){
	for(int i = 1; i <= n+k; i++){
		p[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		//cout << u << " " << v << " " << w << endl;
		if(!f[u] || !f[v]){
			continue;
		}
		if(get(u) != get(v)){
			p[get(u)] = get(v);
			//cout << u << " " << v << " " << w << endl;
			fe[i] = 1;
			sum += w;
		}
	}
}
void kruskal1(){
	for(int i = 1; i <= n+k; i++){
		p[i] = i;
	}
	for(int i = 0; i <= e1.size(); i++){
		int u = e1[i].u, v = e1[i].v, w = e1[i].w;
		//cout << u << " " << v << " " << w << endl;
		if(!f[u] || !f[v]){
			continue;
		}
		if(get(u) != get(v)){
			p[get(u)] = get(v);
			//cout << u << " " << v << " " << w << endl;
			sum += w;
		}
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	//cout << m << endl;
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &e[i].u, &e[i].v, &e[i].w);
	}
	for(int i = 1; i <= n; i++){
		f[i] = 1;
	}
	for(int i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%lld", &a[i][j]);
			e[++m].u = n+i;
			e[m].v = j;
			e[m].w = a[i][j];
		}
	}
	sort(e+1, e+1+m, cmp);
	sum = 0;
	kruskal();
	ans = min(ans, sum);
	for(int i = 1; i <= k; i++){
		sum = 0;
		f[n+i] = 1;
		sum += c[i];
		kruskal();
		ans = min(ans, sum);
		f[n+i] = 0; 
	}
	for(int i = 1; i <= m; i++){
		if(fe[i]){
			e1.push_back(e[i]);
		}
	}
	for(int i = 0; i < (1<<k); i++){
		sum = 0;
		for(int j = 1; j <= k; j++){
			if(i & (1<<(j-1))){
				f[n+j] = 1;
				sum += c[j];
			}
		}
		//cout << i << " " << sum << endl;
		kruskal1();
		//cout << i << " " << sum << endl;
		ans = min(ans, sum);
		for(int j = 1; j <= k; j++){
			if(i & (1<<(j-1))){
				f[n+j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}
