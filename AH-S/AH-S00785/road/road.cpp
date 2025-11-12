#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
typedef long long LL;
const int M = 1e6 + 10, N = 1e4 + 10;
struct Edge{
	int u, v, w;
}e[M*2], tmp[M*2], new_e[M*2];
int n, m, k, a[15][N], c[15], fa[N], tn, mm;
int findfa(int x) {
	if (x == fa[x]) return x;
	return fa[x] = findfa(fa[x]);
}
bool cmp(const Edge &x, const Edge &y) {
	return x.w < y.w;
}
LL mintree() {
	rep(i, 1, n) fa[i] = i;
	sort(e + 1, e + 1 + m, cmp);
	int cnt = 0; LL ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = e[i].u, y = e[i].v;
		int fax = findfa(x), fay = findfa(y);
		if (fax == fay) continue;
		cnt++; ans += e[i].w;
		fa[fax] = fay;
	}
	return ans;
}
LL mintree2() {
	rep(i, 1, n) fa[i] = i;
	int cnt = 0; LL ans = 0;
	for (int i = 1; i <= mm; i++) {
		int x = new_e[i].u, y = new_e[i].v;
		int fax = findfa(x), fay = findfa(y);
		if (fax == fay) continue;
		cnt++; ans += new_e[i].w;
		fa[fax] = fay;
		if (cnt == n-1) break;
	}
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; tn = n;
	rep(i, 1, m) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	rep(i, 1, k) {
		scanf("%d", &c[i]);
		rep(j, 1, n) scanf("%d", &a[i][j]);
	}
	sort(e + 1, e+ 1 + m, cmp);
	if (k == 0) { //k = 0
		cout << mintree() << endl;
		return 0;
	}
	bool flag = 1;//A
	rep(i, 1, k) if (c[i] != 0) flag = 0;
	if (flag) {
		rep(i, 1, k) {
			int id = 0;
			rep(j, 1, n) {
				if (a[i][j] == 0) {id = j; break;}
			}
			rep(j, 1, n) {
				if (id != j) {
					e[++m].u = id, e[m].v = j;
					e[m].w = a[i][j];
				}
			}
		}
		cout << mintree() << endl;
		return 0;
	}
	LL ans = -1;
	rep(i, 0, (1<<k)-1) {
		LL sum = 0, num = 0; n = tn; mm = 0;
		rep(j, 1, k) {
			if ((i >> (j-1)) & 1) {
				++n; sum += c[j];
				rep(i,1,tn) {
					tmp[++num].u = n; tmp[num].v = i;
					tmp[num].w = a[j][i];
				}
			}
		}
		sort(tmp+1, tmp+1+num, cmp);
		int ii = 1, j = 1;
		while(ii <= m && j <= num) {
			if (e[ii].w <= tmp[j].w) new_e[++mm] = e[ii++];
			else new_e[++mm] = tmp[j++];
		}
		while(ii <= m) new_e[++mm] = e[ii++];
		while(j <= num) new_e[++mm] = tmp[j++];
		if (ans == -1) ans = mintree2()+sum;
		else ans = min(ans, mintree2()+sum);
	}
	cout << ans << endl;
	return 0;
}
