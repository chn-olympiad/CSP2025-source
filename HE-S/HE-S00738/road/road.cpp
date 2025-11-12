#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL N = 1e4 + 14, M = 1e1 + 11;
LL n, m, k, w[N][N], c[M], ans = 9e18;
vector<LL> vc[N];
bool f[M], flag;
void dfs(LL now, LL cnt, LL num)
{
	if(ans <= num) return;
	if(cnt == n)
	{
		ans = min(ans, num);
		return;
	}
	for(LL i = 0; i < vc[now].size(); i++)
	{
		LL nxt = vc[now][i];
		if(f[nxt]) continue;
		f[nxt] = 1;
		if(nxt > n) dfs(nxt, cnt, num + c[nxt] + w[nxt][now]);
		else dfs(nxt, cnt + 1, num + w[nxt][now]);
		f[nxt] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	flag = 1;
	for(LL i = 1, u, v, d; i <= m; i++)
	{
		cin >> u >> v >> d;
		w[u][v] = w[v][u] = d;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	for(LL i = n + 1; i <= n + k; i++)
	{
		cin >> c[i];
		if(c[i]) flag = 0;
		for(LL j = 1; j <= n; j++)
		{
			cin >> w[i][j];
			if(w[i][j]) flag = 0;
			w[j][i] = w[i][j];
			vc[i].push_back(j);
			vc[j].push_back(i);
		}
		if(flag) break;
	}
	if(flag)
	{
		cout << 0 << endl;
		return 0;
	}
	f[1] = 1;
	dfs(1, 1, 0);
	cout << ans << endl;
	return 0;
}
