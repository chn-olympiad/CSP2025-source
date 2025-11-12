#include <bits/stdc++.h>
#define space putchar(' ')
#define newline puts("")
#define int long long
using namespace std;

template <typename T> inline void read(T &x){
	x = 0;
	short _ = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') _ = -_;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= _;
}
template <typename T> inline write(T x){
	short _ = 0;
	char s[20];
	if(x < 0) x = -x, putchar('-');
	do s[++_] = x % 10, x /= 10; while(x);
	while(_) putchar(s[_--] ^ 48);
}

typedef pair <int, int> pii;
const int N = 100005, M = 1000005, K = 15;
int n, m, k, tot, c[K], fa[N], ans;
bool A = 1;
vector <pii> g[N + K];
struct node{
	int u, v, w;
}e[M + N * K];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1, u, v, w; i <= m; ++i){
		read(u), read(v), read(w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		e[++tot] = {u, v, w};
	}
	for(int i = 1; i <= k; ++i){
		read(c[i]);
		if(c[i] != 0) A = 0;
		for(int j = 1, w; j <= n; ++j){
			read(w);
			g[j].push_back({n + i, w});
			g[n + i].push_back({j, w});
			e[++tot] = {j, n + i, w};
		}
	}
	if(k == 0 || A){
		for(int i = 1; i <= n + k; ++i) fa[i] = i;
		sort(e + 1, e + tot + 1, [](node x, node y){return x.w < y.w;});
		for(int i = 1, j = 0; i <= tot && j <= n + k - 1; ++i){
			int x = e[i].u, y = e[i].v;
			if(find(x) != find(y)){
				fa[fa[x]] = fa[y];
				ans += e[i].w;
				++j;
			}
		}
		write(ans);
	}
	else{
		for(int i = 1; i <= m; ++i){
			ans += e[i].w;
		}
		write(ans);
	}
	return 0;
}
//5 8 0
//1 4 6
//1 5 1
//2 3 7
//2 4 5
//2 5 8
//3 4 4
//3 5 2
//4 5 4

//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//0 1 8 2 4
//0 1 3 2 4
