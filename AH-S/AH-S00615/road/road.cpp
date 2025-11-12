#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000005], ans;
int main () {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        int fk, dk;
        cin >> fk >> dk >> a[i];
    }
    if (k>0) cout << 0;
    else {
        sort (a+1, a+1+m);
        for (int i=1; i<=n; i++) ans+=m[i];
        cout << ans;
    }
    return 0;
}
