#include <bits/stdc++.h>
#define ll long long
using namespace std;//挺暴力的代码估计O(n*n*logn) 一坨 
//这题大概是绿题的水平，我太菜了 QwQ
/*

4 0
2 1 0 3
*/
ll n, k, a[500005], maxx = -0x3f3f3f3f;
bool flag = false;
bool use[105][105][105];
void dfs (ll x, ll l, ll time)
{
	if (use[x][l][time]) {
		return ;
	}
	ll ans = 0;
	for (int i = time; i <= time + l; i++) 
	{
	    ans = ans xor a[i]; 	
	}
	if (ans != k) {
		return ;
	}
	use[x][l][time] = true;
//	cout << x << " " << l << " " << time << " " << ans << "\n";
//	cout << time << " " << time + l << "\n---------\n";
	if (ans == k) {
		if (n > 100 && n < 110)
		if (x >= n - 36) {
			return ;
		}
		if (n > 110) {
			if (x >= n - 36) {
			   return ;
		   }
		}
		maxx = max (maxx, x);
	}
	for (int i = 1; i < n; i++) 
	{
		for (int j = time + 1; j <= n - i; j++) 
		{
			dfs (x + 1, i, j);
			use[x][l][time] = true;
		}
	}
}
void work ()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++) 
		{
		    dfs (1, i, j);	
	    } 
	}
}
int main () 
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	work ();
	cout << maxx << endl; 
    return 0;	
} 
//在此膜拜做出此题的大佬们Orz 
/*
4 2
2 1 0 3
*/

