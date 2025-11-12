//CSP 2025 RP++
#include<bits/stdc++.h>
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define int long long
using namespace std;
const int N = 1e4+5, M = 1.2e7+5;
//bool start;
int n, m, k, cnt = 1, ans, c[15], a[15][N], f[N];
struct Edge{
	int u, v, w;
	bool operator < (const Edge &b){
		return w < b.w;
	}
} e[M];
//bool eend;
template<typename Tp> inline void read(Tp &x){
	x = 0; char c; bool f = false;
	for(c = gc(); !isdigit(c); c = gc()) if(c == '-') f = true;
	for( ; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
	x = f ? -x : x;
}
inline int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
}
inline void merge(int x, int y){
	x = find(x), y = find(y);
	f[x] = y;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	cerr << (&start - &eend) / 1024.0 / 1024 << "MiB.\n";
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i++) read(e[i].u), read(e[i].v), read(e[i].w);
	for(int i = 1; i <= k; i++){
		read(c[i]);
		for(int j = 1; j <= n; j++){
			read(a[i][j]);
		}
		if(n <= 1000){
			for(int j = 1; j < n; j++){
				for(int l = j + 1; l < n; l++){
					e[++m] = {j, l, a[i][j] + a[i][l]};
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) f[i] = i;
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++){
//		if(cnt == n) break;
//		printf("i=%lld: %lld,%lld,%lld", i, e[i].u, e[i].v, e[i].w);
		if(find(e[i].u) != find(e[i].v)){
//			cnt++;
//			cout << e[i].u << ' ' << e[i].v << endl;
			merge(e[i].u, e[i].v);
			ans += e[i].w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
