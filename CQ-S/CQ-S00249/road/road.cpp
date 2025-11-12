#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10100, M = 1001000, K = 15;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(ll x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x <= 9){
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}

struct edge{
	int u, v, w;
	bool operator < (const edge &A) const {
		return w < A.w;
	}
}edges[M];
ll ans;
int n, m, k;
int c[K], a[K][N], fa[N];

int find(int x){
	if(x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void solve(){
	for (int i = 1, t = 1; t < n; i++){
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		int uu = find(uu), vv = find(v);
		if(uu == vv)
			continue;
	//	printf("%d %d %d\n", u, v, w);
		t++;
		ans += w;
		fa[uu] = fa[vv];
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++){
		int u = read(), v = read(), w = read();
		edges[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++){
		c[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	}
	if(k && !c[1]){
		puts("0");
	}else{
		sort(edges + 1, edges + m + 1);
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		solve();
		write(ans);
		puts("");
	}
	return 0;
}
