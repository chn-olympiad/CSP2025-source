#include <bits/stdc++.h>
using namespace std;
int a[510], n, m, ans;
bool vis[1010];
string s;

void dfs(int mg, int u){
	if(u == n)
	{
		if(n-mg >= m)
		{
			ans ++;
			ans %= 998244353;
		}
		return;
	}
	
	for(int i = 1; i <= n; i ++)
	{
		if(vis[i] == 0)
		{
			if(a[i] <= mg)
			{
				vis[i] = 1;
				dfs(mg+1, u+1);
				vis[i] = 0;
			}
			else
			{
				vis[i] = 1;
				if(s[u] == '1') dfs(mg, u+1);
				else dfs(mg+1, u+1);
				vis[i] = 0;
			}
			
		}
	}
	return ;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans;
	return 0;
} 
