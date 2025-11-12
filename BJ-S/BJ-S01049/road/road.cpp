#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
const int M = 1500005;

int n, m, k, x, c[N], tot; bool u[N] = {0, 1}; ll ans;
struct edge {int st, ed, wt; } e[M];

bool cmp(edge a, edge b) {return a.wt < b.wt; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> e[++tot].st >> e[tot].ed >> e[tot].wt;
	if(k) for(int i = 1; i <= k; i++)
	{
		cin >> x;
		for(int j = 1; j <= n; j++) {cin >> c[j]; if(c[j] == 0) x = j; }
		for(int j = 1; j <= n; j++) if(j != x) {e[++tot].st = x; e[tot].ed = j; e[tot].wt = c[j]; }
	}
	sort(e + 1, e + tot + 1, cmp);
	for(int i = 1; i <= tot; i++)
	{
		if(u[e[i].st] && u[e[i].ed]) continue;
		u[e[i].st] = u[e[i].ed] = 1, ans += e[i].wt;
	}
	cout << ans;
	
	return 0;
}