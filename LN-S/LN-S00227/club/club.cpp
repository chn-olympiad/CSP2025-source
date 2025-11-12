#include<bits/stdc++.h>
using namespace std;

struct A{
    int id, v;
}a[100001], b[100001], c[100001];
int h[100001][5], f[100001], T, n, ans, t;
bool cmp(A x, A y){
    return x.v > y.v;
}

inline void dfs(int i, int d, int e){
    if(d <= 0){
        ans = max(ans, t);
        return;
    }
    for(int k = 1; k <= n; k++){
        if(!f[k]){
            f[k] = true;
            if(e < n / 2){
                t += h[k][i];
                dfs(i, d - 1, e + 1);
                t -= h[k][i];
            }
            t += h[k][i];
            dfs(i + 1, d - 1, 1);
            t -= h[k][i];
            f[k] = false;
        }
    }
}

int main (  ) {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        bool aa = true, bb = true;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            h[i][1] = x; h[i][2] = y; h[i][3] = z;
            if(z != 0 || y != 0){
                aa = false;
            }
            if(z != 0){
                bb = false;
            }
            a[i].v = x;
            b[i].v = y;
            c[i].v = z;
            a[i].id = b[i].id = c[i].id = i;
        }
        if(n == 2){
            int t = 0;
            t = max(t, a[1].v + b[2].v);
            t = max(t, a[1].v + c[2].v);
            t = max(t, a[2].v + b[1].v);
            t = max(t, a[2].v + c[1].v);
            t = max(t, b[1].v + c[2].v);
            t = max(t, b[2].v + c[1].v);
            printf("%d\n", t);
            continue;
        }
        sort(a + 1, a + n + 1, cmp);
        sort(b + 1, b + n + 1, cmp);
        sort(c + 1, c + n + 1, cmp);
        if(aa){
            for(int i = 1; i <= n / 2; i++){
                ans += a[i].v;
            }
            printf("%d\n", ans);
            continue;
        }
        ans = 0;
        int cnt = n;
        for(int i = 1; i <= n; i++){
            t = 0;
            dfs(i, cnt, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
