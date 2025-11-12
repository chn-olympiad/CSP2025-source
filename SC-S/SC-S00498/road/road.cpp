#include<bits/stdc++.h>
#define nmf(i,s,e) for(int i=s;i<=e;i++)
#define ref(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct edge {
	int u, v;
	LL w;
} e[3000005];
vector<edge> grh;
int fa[20005];
int find(int x) {
	return (fa[x] == x) ? (x) : (fa[x] = find(fa[x]));
}
LL v[15][10005], c[15];
void solve() {

	int n, m, k;
	cin >> n >> m >> k;
	nmf(i, 1, n)fa[i] = i;
	int ui, vi;
	LL wi;
	nmf(i, 1, m) {
		cin >> ui >> vi >> wi;
		e[i] = {ui, vi, wi};
	}
	nmf(i, 1, k) {
		cin >> c[i];
		nmf(j, 1, n) {
			cin >> v[i][j];
		}
	}
	if (k <= 5 || n <= 1000) {
		sort(e + 1, e + 1 + m, [](const edge &x, const edge &y) {
			return x.w < y.w;
		});
		int ct = 0;
		nmf(i, 1, m) {
			if (find(e[i].u) == find(e[i].v))continue;
			ct++;
			fa[find(e[i].u)] = find(e[i].v);
			grh.emplace_back(e[i]);
			if (ct == n - 1)break;
		}
		nmf(i, 1, k) {
			nmf(j, 1, n) {
				grh.emplace_back(edge{n + i, j, v[i][j]});
			}
		}
		sort(grh.begin(), grh.end(), [](const edge &x, const edge &y) {
			return x.w < y.w;
		});
		int dot;
		LL ans = LLONG_MAX;
		nmf(S, 0, (1 << k) - 1) {
			dot = n + __builtin_popcount(S);
			LL ret = 0;
			nmf(i, 1, n)fa[i] = i;
			nmf(i, n + 1, n + k) {
				fa[i] = i;
				if (S & (1 << (i - n - 1)))ret += c[i - n];
			}
			for (auto ei : grh) {
				if (ei.u > n)
					if (((S >> (ei.u - n - 1)) & 1) == 0)continue;
				if (find(ei.u) == find(ei.v))continue;
				dot--;
				ret += ei.w;
				fa[find(ei.u)] = find(ei.v);
				if (!dot)break;
			}
			ans = min(ans, ret);
		}
		cout << ans << endl;
		return;
	}

	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	while (T--)solve();
	return 0;
}