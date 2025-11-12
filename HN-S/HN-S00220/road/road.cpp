#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n, m, k, ans;
struct node {
	int u, v, w;
}a[M];
int f[N];
bool cmp(node A,node B) {
	return A.w < B.w;
}
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
void K() {
	int cnt = 0;
	for(int i = 1; i <= m;i ++) {
		int u = find(a[i].u);
		int v = find(a[i].v);
		if(u == v) continue;
		cnt ++;
		ans += a[i].w;
		if(cnt == n - 1) return;
		f[u] = v;
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i ++) f[i] = i;
	for(int i = 1;i <= m;i ++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + m + 1, cmp);
	K();
	cout << ans << '\n';
	return 0;
}


/*
4 4 0
1 3 1
1 2 2
2 4 3
3 4 4
*/







