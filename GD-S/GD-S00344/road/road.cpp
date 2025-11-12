#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 7, M = 1e6 + 7;
struct edge{
	int x, y;
	ll z;
}e[M << 1], g[M << 1]; 
struct town{
	ll c;
	ll pg[N];
}t[20];
int n, m, k;
int tot;
int fa[N];
int res;
ll ans = LLONG_MAX;
void add(int x, int y, ll z){
	e[++tot] = {x, y, z};
}
bool cmp1(edge a, edge b){
	return a.z < b.z;
}
int get(int x){
	if(x == fa[x]) return x;
	else return fa[x] = get(fa[x]);
}
void init(){
	for(int i = 1; i <= n + 20; i++) fa[i] = i;
}
ll min_tree(){
	init();
	for(int i = 1; i <= tot; i++) g[i] = e[i];
	ll sum = 0;
	sort(g + 1, g + tot + 1, cmp1);
	int cnt = n + res;
	for(int i = 1; i <= tot && cnt != 1; i++){
		int fx = get(g[i].x), fy = get(g[i].y);
		if(fx != fy){
			sum += g[i].z;
			cnt--;
			fa[fx] = fy;
		}
	}
	return sum;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int x = 0, y = 0;
		ll z = 0;
		scanf("%d%d%lld", &x, &y, &z);
		add(x, y, z);
		g[i] = e[i];
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= k; i++){
		scanf("%lld", &t[i].c);
		for(int j = 1; j <= n; j++){
			scanf("%lld", &t[i].pg[j]);
		}
	}
	for(int i = (1 << k) - 1; i >= 0; i--){
		int tot2 = tot;
		res = 0;
		ll sum = 0;
		bool flg = 0;
		for(int j = 1; j <= k; j++){
			if((i >> (j - 1)) & 1){
				res++;
				sum += t[j].c;
				for(int l = 1; l <= n; l++){
					add(l, res + n, t[j].pg[l]);
				}
			}
			if(sum >= ans){
				flg = 1;
				break;
			}
		}
		if(!flg) ans = min(ans, min_tree() + sum);
		tot = tot2;
	}
	printf("%lld\n", ans);
	return 0;
}
