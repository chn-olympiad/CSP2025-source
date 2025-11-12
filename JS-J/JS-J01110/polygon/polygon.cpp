#include <bits/stdc++.h>
using namespace std;
int n, f[50001], a[50001], ans;
void dfs(int deep, int last)
{
    if(deep >= 3)
    {
        int x[5001], num = 0, sum = 0, maxx = INT_MIN;
        for(int i = 1;i <= n;i++) if(f[i] == 1) x[++num] = a[i], sum += a[i], maxx = max(maxx, a[i]);
        if(sum > maxx * 2) 
        {
            ans++;
            // for(int i = 1;i <= num;i++) cout << a[i] << " ";
            // cout << endl;
        }
    }
    for(int i = last + 1;i <= n;i++) if(f[i] == 0) f[i] = 1, dfs(deep + 1, i), f[i] = 0;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}