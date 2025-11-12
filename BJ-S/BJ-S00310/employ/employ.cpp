#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 505;
const int MOD = 998244353;
int n,m;
char s[MAXN];
int c[MAXN];
int dp[1 << 18][19];

inline void add_eq(int &x,int d){
    x += d;
    if (x >= MOD)x -= MOD;
}

int main(){
    #ifndef kevin
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    scanf("%s",s + 1);
    for (int i = 1;i <= n;i ++)scanf("%d",c + i);
    if (n <= 18){
        dp[0][0] = 1;
        for (int S = 0;S < (1 << n);S ++){
            int sz = __builtin_popcount(S);
            for (int i = 0;i <= sz;i ++){
                // printf("dp %d %d = %d\n",S,i,dp[S][i]);
                for (int j = 1;j <= n;j ++){
                    if (S >> (j - 1) & 1)continue;
                    if (s[sz + 1] == '0' || i >= c[j])add_eq(dp[S | 1 << (j - 1)][i + 1],dp[S][i]);
                    else add_eq(dp[S | 1 << (j - 1)][i],dp[S][i]);
                }
            }
        }
        int ans = 0;
        for (int i = 0;i <= n - m;i ++)
            add_eq(ans,dp[(1 << n) - 1][i]);
        printf("%d\n",ans);
        return 0;
    }
    int fac = 1;
    for (int i = 1;i <= n;i ++)fac = (ll)fac * i % MOD;
    if (m == 1){
        sort(c + 1,c + n + 1);
        int cnt = 0;
        int ans = 1;
        for (int i = 1;i <= n;i ++){
            if (s[i] == '1'){
                int vals = lower_bound(c + 1,c + n + 1,i) - c - 1;
                ans = (ll)ans * (vals - cnt) % MOD;
                cnt ++;
            }
        }
        for (int i = 1;i <= n - cnt;i ++)ans = (ll)ans * i % MOD;
        ans = (fac - ans + MOD) % MOD;
        printf("%d\n",ans);
        return 0;
    }
    
    for (int i = 1;i <= n;i ++)
        if (s[i] == '0' || c[i] == 0){
            printf("0\n");
            return 0;
        }
    printf("%d\n",fac);
    return 0;
}