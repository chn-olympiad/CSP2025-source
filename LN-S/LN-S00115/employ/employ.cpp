#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510;
const LL MOD = 998244353;

int n, m;
char s[N];
int c[N];
int p[N];
bool used[N];
LL ans;

void dfs(int now){
    if(now == n + 1){
        int fail_cnt = 0;
        for(int i = 1; i <= n; i++){
            if(fail_cnt >= c[p[i]]){
                fail_cnt++;
                continue;
            }
            if(s[i] == '0')
                fail_cnt++;
        }
        if(n - fail_cnt >= m) ans++;
        if(ans >= MOD) ans -= MOD;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            p[now] = i;
            dfs(now + 1);
            used[i] = 0;
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    if(n > 18){
        puts("0");
        return 0;
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}
