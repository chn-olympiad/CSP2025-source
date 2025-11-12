
#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 5000 + 5;
inline void fre()
{
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    return ;
}
int n, a[MAXN], pre[MAXN];
int ans = 0;
inline int maxx(int a, int b){
    if (a > b) return a;
    return b;
}
inline void f(int cmp, int step, int sum, int i, int d)
{
    if (i >= cmp){
        if (d * 2 < sum) ans++;
        return ;
    }
    for (rg int j = step + 1; j <= n; j++){
        f(cmp, j, sum + a[j], i + 1, maxx(d, a[j]));
    }
    return ;
}
signed main()
{
    fre();
    scanf ("%lld", &n);
    for (rg int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for (rg int i = 3; i <= n; i++){
        for (rg int j = 1; j <= n - i + 1; j++){
            f(i, j, a[j], 1, a[j]);
        }
    }
    printf ("%lld\n", ans);
    return 0;
}
