#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define N (int)(1e4 + 5)
#define M (int)(2e6 + 5)
#define K 12
#define mod (int)(1e9 + 7)
#define inf (int)(1e18)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = ch =='-' ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, k, u, v, flag, gcnt;
ll w, cnt, ans = inf;
int c[K], a[K][N], fa[N + K];
struct edge{int u, v, w;}G[M], g[M];
bool cmp(edge p, edge q){return p.w < q.w;}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void solve(){
	n = read(), m = read(), k = read();
	qwe(i, 1, m) G[i] = {read(), read(), read()};
	qwe(i, 1, k){
		c[i] = read();
		if(c[i]) flag = 1;
		qwe(j, 1, n) a[i][j] = read();
	}
	if(!flag){
		qwe(i, 1, n){
			fa[i] = i;
			qwe(j, i + 1, n){
				int minn = 0x3f3f3f3f;
				qwe(l, 1, k) minn = min(minn, a[l][i] + a[l][j]);
				G[++m] = {i, j, minn};
			}
		}
//		printf("%d\n", m);
		sort(G + 1, G + m + 1, cmp);
		int ecnt = 0;
		qwe(i, 1, m){
			int u = find(G[i].u), v = find(G[i].v), w = G[i].w;
			if(u == v) continue;
//			printf("%d %d %d\n", G[i].u, G[i].v, G[i].w);
			ecnt++;
			fa[u] = v;
			cnt += (ll)w;
			if(ecnt == n - 1) break;
		}
		printf("%lld", cnt);
	}
	else{
		qwe(now, 0, (1 << k) - 1){
			gcnt = cnt = 0;
			qwe(i, 1, m) g[++gcnt] = G[i];
			int dcnt = n;
			qwe(i, 1, n + k) fa[i] = i;
			qwe(i, 1, k){
				if(now & (1 << (i - 1))){
					cnt += (ll)c[i];
					dcnt++;
					qwe(j, 1, n) g[++gcnt] = {n + i, j, a[i][j]};
				}
			}
			sort(g + 1, g + gcnt + 1, cmp);
			int ecnt = 0;
//			printf("%d\n", now);
			qwe(i, 1, gcnt){
				int u = find(g[i].u), v = find(g[i].v), w = g[i].w;
				if(u == v) continue;
//				printf("%d %d %d\n", g[i].u, g[i].v, g[i].w);
				ecnt++;
				fa[u] = v;
				cnt += (ll)w;
				if(cnt > ans) break;
				if(ecnt == dcnt - 1) break;
			}
			if(ecnt == dcnt - 1) ans = min(ans, cnt);
//			printf("%d\n", cnt);
		}
		printf("%lld", ans);
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	T = read();
	while(T--) solve();
	return 0;
}
/*

Makka pakka :D
*/

