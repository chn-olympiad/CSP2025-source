#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
struct node {int u, v, w;};
bool cmp(node x, node y) {return x.w < y.w;}
int n, m, k, c[20], a[20][10010]; 
node e[1000010], e1[1000010], e2[1000010];
int top1, top2;
int fa[1000010];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool flagA = 1; 
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		if(c[i]) flagA = 0;
		int flg = 0;
		for(int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			if(a[i][j] == 0) flg = 1;
		}
		flagA &= flg;
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int uu = find(e[i].u), vv = find(e[i].v);
		if(uu != vv) {
			fa[uu] = vv;
			e1[++top1] = e[i];
		}
	}
	int ans = inf;
	for(int S = 0; S < (1ll << k); S++) {
		if(flagA && S != ((1ll << k) - 1)) continue;
		top2 = top1; for(int i = 1; i <= top1; i++) e2[i] = e1[i];
		
		int cst = 0;
		for(int i = 1; i <= k; i++) {
			if((S >> (i - 1)) & 1) {
				cst += c[i];
				for(int j = 1; j <= n; j++) {
					node xxx; xxx.u = i + n, xxx.v = j, xxx.w = a[i][j];
					e2[++top2] = xxx; 
				}
			}
		}
		
		
		sort(e2 + 1, e2 + top2 + 1, cmp);
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		for(int i = 1; i <= top2; i++) {
			int uu = find(e2[i].u), vv = find(e2[i].v);
			if(uu != vv) {
				fa[uu] = vv;
				cst += e2[i].w;
			}
		}
		ans = min(ans, cst);
	}
	printf("%lld\n", ans);
	
	return 0;
}
