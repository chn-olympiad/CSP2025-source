#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 100010;

int n;
ll k, a[N];
bool vis[N];
int ans = -1;

void dfs (int dep, int cnt) {
    if (dep > n) {
        ans = max(ans, cnt);
        return ;
    }
    dfs (dep + 1, cnt);
    for (int r = dep; r <= n; r ++ ) {
        if (!vis[r]) {
            ll val = 0;
            for (int i = dep; i <= r; i ++ )  {
                val ^= a[i];
                if (val == k) {
                    for (int i = dep; i <= r; i ++ ) vis[i] = 1;
                    dfs (dep + 1, cnt + 1);
                    for (int i = dep; i <= r; i ++ ) vis[i] = 0;
                }
            }
        }
    }
}

int main (){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d", &n);
    scanf("%lld", &k);
    bool all1 = 1, all01 = 1;
    for (int i = 1; i <= n; i ++ ) {
        scanf("%lld", &a[i]);
        if (a[i] != 1) all1 = 0;
        if (a[i] != 1 && a[i] != 0) all01 = 0;
    }

    if (all1 && k == 0) {
        printf("%d\n", n / 2);
        return 0;
    }

    if (all01 && k <= 1) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] == 1) cnt++ ;
        }
        if (k == 1) printf("%d\n", cnt);
        else printf("%d\n", n - cnt);
        return 0;
    }


    dfs (1, 0);
    cout << ans;


    return 0;
}
