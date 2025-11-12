#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N][5], maxn = -1e9, n, ca, cb, cc, ans;
void dfs(int x){
    if(ca > (n >> 1)) return ;
    if(cb > (n >> 1)) return ;
    if(cc > (n >> 1)) return ;
    if(x > n){
        maxn = max(maxn, ans);
        return ;
    }
    ca++;
    ans += a[x][1];
    dfs(x + 1);
    ca--;
    ans -= a[x][1];

    cb++;
    ans += a[x][2];
    dfs(x + 1);
    cb--;
    ans -= a[x][2];

    cc++;
    ans += a[x][3];
    dfs(x + 1);
    cc--;
    ans -= a[x][3];
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= 3;j++) cin >> a[i][j];
        
        maxn = -1e9, ca = 0, cb = 0, cc = 0;
        dfs(1);
        cout << maxn << endl;
    }
    return 0;
}