#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int n, a[5010], ans, c[5010];
inline void dfs(int ax, int lo, int i){
    if ( i == lo + 1 ){
        int x = 0;
        for ( int j = 1; j <= lo; j++ )
            x += c[j];
        if ( x > ax * 2 )
            ans++, ans %= p;
        return;
    }
    for ( int j = i + 1; j <= n; j++ ){
        c[++i] = a[j];
        if ( a[j] > ax )
            dfs(a[j], lo, i + 1);
        else
            dfs(ax, lo, i + 1);
    }
    return;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &a[i]);
    for ( int i = 3; i <= n; i++ )
        dfs(0, i, 0);
    printf("%d", ans);
    return 0;
}
