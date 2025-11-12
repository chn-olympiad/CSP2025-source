#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, s, cnt, maxn = INT_MIN;
int a[N], sum[N][N];
struct node {
    int l, r;
}f[N];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> s;
    sum[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= i; j++)
            sum[i][j] = (sum[i - 1][j] ^ a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++){
            if (sum[i][j] == s){
                bool vis = 0;
                for (int k = 1; k <= cnt; k++){
                    if (j == f[k].l && i == f[k].r){
                        vis = 1;
                        break;
                    }
                }
                if (!vis) f[++cnt].l = j; f[cnt].r = i;
            }
        }
    }
    for (int i = 1; i <= cnt; i++){
        int x = 0;
        for (int j = 1; j <= cnt; j++){
            if (f[j].r <= f[i].r && f[j].l <= f[i].l) continue;
            if (f[j].l >= f[i].l && f[j].r <= f[i].r) continue;
            if (f[j].r <= f[i].l && f[j].r >= f[i].r) continue;
            if (f[j].l <= f[i].r && f[j].r >= f[i].r) continue;
            x++;
        }
        maxn = max(maxn, x);
    }
    cout << maxn;
    return 0;
}
