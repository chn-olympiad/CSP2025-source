#include<bits/stdc++.h>
using namespace std;
int n, a[5005], zh;
long long ans;
void dfs(int s, int maxn, int zb, int h){
    int max1 = maxn;
    maxn = max(maxn, a[zb]);
    h += a[zb];
    if (s == 0 ){
        if (h == zh) {
            if ( max1 * 2 < h - a[zb])
                ans++;
        }
        else if (maxn * 2 < h) ans++;
        return;
    }
    if (n - zb + 1 == s){
        for (int i = zb + 1; i <= n; i++){
            h += a[i];
            maxn = max(a[i], maxn);
        }
        if (maxn * 2 < h)
            ans++;
        return;
    }
    for (int i = zb; i <= n - s; i++)
        dfs(s - 1, maxn, i + 1, h);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], zh += a[i];
    for (int i = n; i >= 3; i--)
        for (int j = 1; j <= n - i + 1; j++)
            dfs(i, 0, j, 0);
    cout << ans;
    return 0;
}
