#include<bits/stdc++.h>
using namespace std;
namespace Luo_ty{
	int read(){
		int ans = 0;
		char ch = 'l';
		while(ch < '0' || ch > '9') ch = getchar();
		while('0' <= ch && ch <= '9'){
			ans = (ans << 3) + (ans << 1) + ch - '0';
			ch = getchar();
		}
		return ans;
	}
	const int MAXN = 1000005;
	struct E{
		int u, v, w;
	}se[MAXN], ne[MAXN];
	bool cmp (E a, E b){
		return a.w < b.w;
	}
	int fa[MAXN], sz[MAXN];
	int belong(int x){
		if(x == fa[x]) return x;
		return fa[x] = belong(fa[x]);
	}
	int Union(int u, int v){
		int x = belong(u), y = belong(v);
		if(x == y) return 0;
		if(sz[x] < sz[y]) swap(x, y);
		fa[y] = x;
		sz[x] += sz[y];
		return 1;
	}
	int lsh[MAXN], _; 
	int a[15][10005], c[15];
	vector<E> e[MAXN];
	int n, m, k;
	long long Kruskal(int lim){
		long long ans = 0;
		for(int i = 1;i <= n + k;i++){
			fa[i] = i;
			sz[i] = 1;
		}
		int cnt = 0;
		for(int i = 1;i <= _;i++){
			for(E j : e[i]){
				if(Union(j.u, j.v)){
					cnt++;
					ans += lsh[i];
					if(cnt == lim - 1) break;
				}
			}
			if(cnt == lim - 1) break;
		}
		return ans;
	}
	int main(){
//		scanf("%d%d%d", &n, &m, &k);
		n = read();
		m = read();
		k = read();
		for(int i = 1, u, v, w;i <= m;i++){
//			scanf("%d%d%d", &u, &v, &w);
			u = read();
			v = read();
			w = read();
			se[i] = (E){u, v, w};
		}
		//先做一次Kruskal缩小边的级别到O(n) 
		sort(se + 1, se + m + 1, cmp);
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			fa[i] = i;
			sz[i] = 1;
		}
		int cnt = 0;
		for(int i = 1;i <= m;i++){
			int u = se[i].u, v = se[i].v, w = se[i].w;
			if(Union(u, v)){
				ans += w;
				ne[++cnt] = se[i];
			}
			if(cnt == n - 1) break;
		}
		//直接状压村庄选不选，如果用桶排序可以消掉log，但是不清楚实际速度谁更快
		//我更倾向于先离散化之后桶排序 
		//离散化之后值域是1e5级别的，而且开O2之后vector效率会快很多 
		for(int i = 1;i < n;i++){
			lsh[++_] = ne[i].w; 
		} 
		for(int i = 1;i <= k;i++){
//			scanf("%d", &c[i]);
			c[i] = read();
			for(int j = 1;j <= n;j++){
//				scanf("%d", &a[i][j]);
				a[i][j] = read();
				lsh[++_] = a[i][j]; 
			}
		}
		sort(lsh + 1, lsh + _ + 1);
		_ = unique(lsh + 1, lsh + _ + 1) - lsh - 1;
		for(int i = 1;i < n;i++){
			ne[i].w = lower_bound(lsh + 1, lsh + _ + 1, ne[i].w) - lsh;
		}
		for(int i = 1;i <= k;i++){
			for(int j = 1;j <= n;j++){
				a[i][j] = lower_bound(lsh + 1, lsh + _ + 1, a[i][j]) - lsh;
			}
		}
		int all = (1 << k); 
		for(int s = 1;s < all;s++){
			for(int i = 1;i < n;i++){
				e[ne[i].w].push_back(ne[i]);
			}
			long long now = 0, cnt = 0;
			for(int i = 1;i <= k;i++){
				if((s >> (i - 1)) & 1){
					now += c[i];
					cnt++;
					for(int j = 1;j <= n;j++){
						e[a[i][j]].push_back((E){j, n + i, a[i][j]});
					}
				}
			}
			ans = min(ans, Kruskal(n + cnt) + now); 
			//清空 
			for(int i = 1;i < n;i++){
				e[ne[i].w].clear();
			}
			for(int i = 1;i <= k;i++){
				if((s >> (i - 1)) & 1){
					for(int j = 1;j <= n;j++){
						e[a[i][j]].clear();
					}
				}
			}
		}
		printf("%lld", ans);
		//到时候记得造一个极限数据跑一下 
		//感觉输入花了很多时间，快读优化应该不小 
		//极限数据要跑1.3s，但是至少80分还是有的
		//改成前向星试了一下，快不了多少，还是跑不进1s 
//		while(1); 
		return 0;
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return Luo_ty::main();
}//Chelsea 2012
//63MB
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
