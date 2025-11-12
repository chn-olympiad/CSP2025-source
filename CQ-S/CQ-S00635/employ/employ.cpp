#include <bits/stdc++.h>
#define llong long long
#define N 1003
using namespace std;

constexpr llong p = 998244353;
int s[N];
int c[N], id[N];
int n, m, cnt;

inline void solve1(){
    llong ans = 1;
    for(int i = 1; i <= n; ++i)
        ans = ans*i%p;
    printf("%lld", ans);
    return;
}

int vis1[N], vis2[N], res;
inline void dfs(int t, int e, int pos){
    if(t == m){
        ++res;
        if(res >= p) res -= p;
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(vis1[i]) continue;
        vis1[i] = true;
        int ne = e+(s[pos]==0||e>=c[i]);
        if(n-ne >= m) 
            dfs(t+(s[pos]==1&&e<c[i]), ne, pos+1);
        vis1[i] = false;
    }
    return;
}

inline void solve2(){
    for(int i = 1; i <= n; ++i)
        id[i] = i;
    dfs(0, 0, 1);
    printf("%d", res);
    return;
}

char st[N];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    scanf("%s", st+1);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &c[i]), cnt += (s[i] = st[i]^'0');
    if(cnt == n) solve1();
    else         solve2();
    return 0;
}
