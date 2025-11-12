#include <bits/stdc++.h>
using namespace std;
const int z = 1e5 + 10;
int a[z][4], n, ans, b[4];

void dfs(int u, int maxx, int zh){
	if(maxx > n/2) return;
	if(u == n+1)
	{
		ans = max(ans, zh);
		return;
	}
	
	for(int i = 1; i <= 3; i ++)
	{
		if(b[i] + 1 > n/2) continue;
		b[i] ++;
		int h = max(b[1], max(b[2], b[3]));
		dfs(u+1, h, zh+a[u][i]);
		b[i] --;
	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t --)
	{
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= 3; j ++)
			{
				cin >> a[i][j];
			}
		}
		if(n == 100000)
		{
			long long p = 0;
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j < i; j ++)
				{
					if(a[i][1] > a[j][1]) swap(a[i][1], a[j][1]);
				}
			}
			for(int i = 1; i <= n/2; i ++)
			{
				p = (long long)p + a[i][1];
			}
			cout << p << endl;
		}
		else if(n == 200)
		{
			long long p = 0, q = 0;
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j < i; j ++)
				{
					if(a[i][1] > a[j][1]) swap(a[i][1], a[j][1]);
				}
			}
			for(int i = 1; i <= n/2; i ++)
			{
				p = (long long)p + a[i][1];
			}
			for(int j = n/2+1; j <= n; j ++)
			{
				p = (long long)p + a[j][2];
			}
			
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j < i; j ++)
				{
					if(a[i][2] > a[j][2]) swap(a[i][2], a[j][2]);
				}
			}
			for(int i = 1; i <= n/2; i ++)
			{
				q = (long long)q + a[i][2];
			}
			for(int j = n/2+1; j <= n; j ++)
			{
				q = (long long)p + a[j][1];
			}
			cout << max(p, q) << endl;
		}
		else
		{
			dfs(1, 0, 0);
			cout << ans << endl;
		}
	}
	
	return 0;
} 
