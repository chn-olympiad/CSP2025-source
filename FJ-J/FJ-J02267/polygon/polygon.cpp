# include <bits/stdc++.h>
using namespace std;
const int BIG =  998244353;
int n, ans = 0;
int a[5005];
bool vis[5005];
void dfs(int step)
{
	if(step > n)
	{
		int maxn = -1e9, tot = 0, have = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] == 1)
			{
				maxn = max(maxn, a[i]);
				have++;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] == 1) tot += a[i];
		}
		//cout << i << " " << j << " " << maxn << " " << tot << "change" << endl; 
		if(tot > 2 * maxn && have >= 3)
		{
			ans = (ans + 1) % BIG;
		}
		return ;
	}
	vis[step] = 1;
	dfs(step + 1);
	vis[step] = 0;
	dfs(step + 1);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
