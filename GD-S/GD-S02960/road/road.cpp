#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int u,v;
	long long w;
} E[int(2e6+5)],F[int(2e4+5)],G[int(2e4+5)];
long long c[15],a[15][int(1e4+5)];

int vat[int(2e4+5)],scnt;

void init(int n) {
	for (int i = 1; i <= n; i++)
		vat[i] = i;
	scnt = n;
}
int find_root(int u) {
	if (vat[u] == u) return u;
	return vat[u] = find_root(vat[u]); 
}
bool meege(int u, int v) {
	int ru = find_root(u);
	int rv = find_root(v);
	if (ru == rv) return 0;
	vat[ru] = rv; scnt--;
	return 1;
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,M,k;
	cin >> n >> M >> k;
	for (int i = 1; i <= M; i++)
		cin >> E[i].u >> E[i].v >> E[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	long long ans = 0; int W = 0;
	sort(E+1,E+M+1,[](node a, node b) {
		return a.w < b.w;
	}); init(n);
	for (int i = 1; i <= M; i++) {
		if (meege(E[i].u,E[i].v)) {
			ans += E[i].w;
			G[++W] = E[i];
		}
		if (scnt == 1) break;
	}

	for (int S = 0; S < (1<<k); S++) {
		long long sum = 0; init(n);
		int m = W; memcpy(F,G,sizeof G);
		for (int i = 1; i <= k; i++)
			if (S & (1<<(i-1))) {
				vat[n+i] = n+i;
				scnt++;
				for (int j = 1; j <= n; j++) 
					F[++m] = {n+i,j,a[i][j]};
				sum += c[i];
			}
		sort(F+1,F+m+1,[](node a, node b) {
			return a.w < b.w;
		});
		for (int i = 1; i <= m; i++) {
			if (meege(F[i].u,F[i].v))
				sum += F[i].w;
			if (scnt == 1) break;
		}
		ans = min(ans,sum);
	}
	cout << ans;
	return 0;
}
// S 组打成依托，怎么会是呢。
// 抱歉，我不属于密码上所描述的。