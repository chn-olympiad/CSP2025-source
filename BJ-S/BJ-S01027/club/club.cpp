//LMY bao you zheng jie bie gua!!!~~~
#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define lop(i, x, y) for (int i = x; i >= y; i--)
#define sort stable_sort
using namespace std;
const int NR = 1e5 + 5;
inline int read(){
    int s = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9'){
        s = s * 10 + c - '0';
        c = getchar();
    }
    return s * f;
}
int n, a[NR][4], cnt[4];
int ans;
int b[4][NR], tail[4];
void test(){
    n = read();
    rep(i, 0, 2){
        cnt[i] = tail[i] = 0;
    }
    ans = 0;
    rep(i, 1, n){
        int maxn = -1, cd = -1;
        rep(j, 0, 2){
            a[i][j] = read();
            if (a[i][j] > maxn){
                cd = maxn;
                maxn = a[i][j];
            }else if (a[i][j] > cd){
                cd = a[i][j];
            }
        }
        ans += maxn;
        rep(j, 0, 2){
            if (a[i][j] == maxn){
                tail[j]++;
                b[j][tail[j]] = maxn - cd;
                cnt[j]++;
                break;
            }
        }
    }
    rep(o, 0, 2){
        if (cnt[o] > n / 2){
            sort(b[o] + 1, b[o] + tail[o] + 1);
            rep(i, 1, cnt[o] - (n / 2)){
                ans -= b[o][i];
            }
        }
    }
    printf("%d\n", ans);
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int _ = read();
    while (_--){
        test();
    }
    return 0;
}
