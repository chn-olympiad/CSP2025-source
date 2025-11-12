#include <bits/stdc++.h>
using namespace std;

vector<int> g[10020];
vector<int> w[10020];
bool vis[10020];
int z[20];
int f[10020];

void dfs(int start, int fa)
{
	if(vis[start]) return;
//	cout << "going " << fa <<" " << start << endl;
	for(int i = 0; i<g[start].size(); i++) {
		if(g[start][i] == fa) continue;
		f[g[start][i]] = min(f[g[start][i]], f[start] + w[start][i]);
//		cout <<f[g[start][i]]<< " " << g[start][i]<<" "<< f[start] <<" " << start <<" "<< w[start][i] << endl;
		vis[start] = true;
		dfs(g[start][i], start);
		vis[start] = false;
	}
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

int main()
{
	freopen("road3.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i<=m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back(y);
		g[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	for(int i = 1; i<=k; i++) {
		cin >> z[i];
		for(int j = 1; j<=n; j++) {
			int mny;
			cin >> mny;
			g[n+i].push_back(j);
			g[j].push_back(n+i);
			w[n+i].push_back(mny);
			w[j].push_back(mny);
		}
	}
	f[0] = f[1] = 0;
	dfs(1, 0);
	int maxn = 0;
	for(int i = 1; i<=n+k; i++) {
		cout << f[i] << " ";
	}
	for(int i = 1; i<=n; i++) maxn = max(maxn, f[i]);
	cout << endl;
	cout << maxn << endl;
	return 0;
}
