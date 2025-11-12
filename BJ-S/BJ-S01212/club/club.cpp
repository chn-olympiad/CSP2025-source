#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int t, n, a[3][maxn];
int dfs(int x, int y, int z, int i, int cnt) {
    if(i == n+1) return cnt;
    int res = 0;
    if(x + 1 <= n/2) res = max(res, dfs(x+1, y, z, i+1, cnt+a[0][i]));
    if(y + 1 <= n/2) res = max(res, dfs(x, y+1, z, i+1, cnt+a[1][i]));
    if(z + 1 <= n/2) res = max(res, dfs(x, y, z+1, i+1, cnt+a[2][i]));
    return res;
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[0][i] >> a[1][i] >> a[2][i];
        cout << dfs(0, 0, 0, 0, 0) << endl;
    }
    return 0;
}