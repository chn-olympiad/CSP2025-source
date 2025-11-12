#include <bits/stdc++.h>
using namespace std;
int n, a[5010]; bool vis[5010];
vector<int> path;
set<vector<int> > kinds;
int MOD = 998244353;
bool cmp1(int i, int j)
{
	return a[i] > a[j];
}
bool check()
{
	int maxx, sum;
	sort(&path[0], &path[0]+path.size(), cmp1);
	for (int i = 0; i < path.size(); i++) sum += path[a[i]];
	if (path[0] * 2 < sum) return true;
	return false;
}
void dfs(int u)
{
	if (u > n) return;
	if (u >= 3) if (check())
	{
		kinds.insert(path);
	}
	for (int i = u; i < n; i++)
	{
		if (!vis[i])
		{
    		path.push_back(i);
	    	vis[i] = true;
	    	dfs(u+1);
	    	vis[i] = false;
	    	path.pop_back();
		}
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dfs(0);
	cout << kinds.size() % MOD;
}