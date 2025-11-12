#include <bits/stdc++.h>
using namespace std;
int a[5010], n;
long long ans;
bool vis[5010], b[5010];

void dfs(int maxx, int zh, int xz, int mb, int dq){
	if(xz == mb)
	{
		if(zh > maxx*2)
		{
			bool h = 0;
			for(int i = 1; i <= n; i ++)
			{
				if(b[i] != vis[i])
				{
					b[i] = vis[i];
					h = 1;
				}
			}
			if(h == 1)
			{
				ans ++;
				ans %= 998244353;
			}
		}
		return;
	}
	
	for(int i = dq; i <= n; i ++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			dfs(max(maxx, a[i]), zh+a[i], xz+1, mb, i);
			vis[i] = 0;
		}
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int p = 0;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 3; i <= n; i ++)
	{
		dfs(0, 0, 0, i, 1);
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
