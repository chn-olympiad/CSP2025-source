#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int MAX_N = 505, MOD = 998244353;

int n, m, s[MAX_N], c[MAX_N], sum0[MAX_N], notdayu[MAX_N];
string in_str;

namespace all_pailie {

    int ans;
    bool vis[11];

    void dfs (int i, int x) {
        if(x > n-m) return;
        if(i == n+1) {
            ++ ans;
            return;
        }
        for(int j = 1; j <= n; j ++) {
            if(!vis[j]) {
                vis[j] = true;
                if(s[i] == 0) {
                    dfs(i+1, x+1);
                }
                else {
                    if(c[j] <= x) dfs(i+1, x+1);
                    else dfs(i+1, x);
                }
                vis[j] = false;
            }
        }
    }

    void run () {
        ans = 0;
        for(int i = 1; i <= 10; i ++) vis[i] = 0;
        dfs(1, 0);
        printf("%d\n",ans);
    }
}

int main () {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    bool s_all_1 = true;
    cin >> in_str;
    for(int i = 1; i <= n; i ++) {
        if(in_str.at(i-1) == '0') s[i] = 0;
        else s[i] = 1;
        sum0[i] = sum0[i-1];
        if(s[i] == 0) {
            ++ sum0[i];
            s_all_1 = false;
        }
    }
    for(int i = 1; i <= n; i ++) {
        scanf("%d",&c[i]);
    }
    sort(c+1, c+1+n);
    int it = 0;
    for(int i = 0; i <= n; i ++) {
        while(it < n && c[it+1] <= i) ++ it;
        notdayu[i] = it;
    }
    if(m == n) {
        LL ans = 1;
        for(int i = 1; i <= n; i ++) {
            if(s[i] == 0 || c[i] == 0) ans = 0;
        }
        if(ans == 0) {
            printf("0\n");
            return 0;
        }
        for(int i = 2; i <= n; i ++) {
            ans = ans * i % MOD;
        }
        printf("%lld\n",ans);
        return 0;
    }
    if(n <= 10) {
        all_pailie::run();
        return 0;
    }
    return 0;
}
