#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
long long ans;
bool vis[5005];
void dfs (int step, int sum, int maxn) {
    if (sum > 2*a[maxn] && step > 3)
        ans = (ans+1)%998244353;
    if (step > n)
        return;
    for (int i = maxn+1; i <= n; i++)
        if (!vis[i]) {
            vis[i] = 1;
            dfs(step+1, sum+a[i], i);
            vis[i] = 0;
        }
}
int main () {
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i]);
    sort (a+1, a+n+1);
    if (a[n] == 1) {
    	printf ("%d", n-2);
    	return 0;
	} 
    dfs(1, 0, 0);
    printf ("%d", ans);
    return 0;
} 
