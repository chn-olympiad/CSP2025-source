#include <bits/stdc++.h>
using namespace std;
int a[500100];
bool vis[500100];
int n, k, ans;

void dfs(int h, int cnt){
	if(cnt == k)
	{
		ans ++;
		return;
	}
	if(h == n) return;
	
	if(vis[h] == 0)
	{
		vis[h] = 1;
		dfs(h+1, cnt xor a[h]);
		vis[h] = 0;
	}
	
	dfs(h+1, cnt);
	return ;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		vis[i] = 1;
		dfs(i, a[i]);
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}
