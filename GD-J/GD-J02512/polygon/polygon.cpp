#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, a[50005], ans; 
bool use[105][105][105], vis[1005];
/*
5
 2 2 3 8 10
*/
void dfs (ll x, ll maxx, ll cnt)
{
	if (use[x][maxx][cnt]) {
		return ;
	}
	if (cnt > maxx * 2) {
//		cout << x <<  " " << maxx << " " << cnt << "\n"; 
		ans++;
		ans %= mod;
	}
	
	use[x][maxx][cnt] = true;
	for (ll i = x + 1; i <= n; i++) 
	{
		ll p = cnt + a[i], q = max (maxx, a[i]);
		dfs (i, q, p);
		dfs (i, maxx, cnt);
	}
	return ;
}
int main () 
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
    	cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++) 
	{
		dfs (i, a[i], a[i]);
		dfs (i, 0, 0);
	}
	cout << ans << endl;
    return 0;	
} 

