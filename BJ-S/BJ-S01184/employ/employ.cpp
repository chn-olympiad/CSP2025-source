#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define y1 Goodbye_1
#define y2 Goodbye_2
#define ll long long
#define o1 first
#define o2 second
#define omp make_pair
#define opb push_back
#define inf 3423423423423423422ll
#define MAX_N 522

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = false;do{c = getchar();if(c == '-')v = true;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c <= ' ' && c != EOF)c = getchar();return c;}

const ll P = 998244353;

inline void add(ll& i, const ll j) { i = (i + j) % P; }

int n, m;
bool s[MAX_N];
int a[MAX_N], pre[MAX_N];
ll C[MAX_N][MAX_N], fac[MAX_N], A[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N], dpl[MAX_N][MAX_N];

void oM()
{
    n = read();
    m = read();
    for(int i = 1; i <= n; i++)
        s[i] = (gtc() == '1');
    for(int i = 1; i <= n; i++)
        a[read()]++;
    pre[0] = a[0];
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    dp[0][0] = 1;
    for(int o = 1; o <= n; o++)
    {
        for(int j = 0; j < o; j++)
            for(int k = 0; k < o && k <= pre[j]; k++)
                dpl[j][k] = dp[j][k], dp[j][k] = 0;
        if(s[o])
        {
            for(int j = 0; j < o; j++) // not rejected, c > j
                for(int k = 0; k < o && k <= pre[j]; k++)
                    if(dpl[j][k])
                        add(dp[j][k], dpl[j][k]);
            for(int j = 0; j < o; j++)
                for(int k = 0; k < o && k <= pre[j]; k++) // rejected, c <= j, j += 1
                    if(dpl[j][k])
                    {
                        ll t = (pre[j] - k) * dpl[j][k] % P;
                        for(int l = 0; l <= a[j + 1] && k + 1 + l <= o; l++)
                            add(dp[j + 1][k + 1 + l], t * C[o - 1 - k][l] % P * A[a[j + 1]][l]);
                    }
        }
        else
        {
            for(int j = 0; j < o; j++) // rejected, c > j, j += 1
                for(int k = 0; k < o && k <= pre[j]; k++)
                    if(dpl[j][k])
                    {
                        ll t = dpl[j][k];
                        for(int l = 0; l <= a[j + 1] && k + l <= o; l++)
                            add(dp[j + 1][k + l], t * C[o - k][l] % P * A[a[j + 1]][l]);
                    }
            for(int j = 0; j < o; j++)
                for(int k = 0; k < o && k <= pre[j]; k++) // rejected, c <= j, j += 1
                    if(dpl[j][k])
                    {
                        ll t = (pre[j] - k) * dpl[j][k] % P;
                        for(int l = 0; l <= a[j + 1] && k + 1 + l <= o; l++)
                            add(dp[j + 1][k + 1 + l], t * C[o - 1 - k][l] % P * A[a[j + 1]][l]);
                    }
        }
        /*printf("%d:\n", o);
        for(int j = 0; j <= o; j++)
            for(int k = 0; k <= o; k++)
                printf("%lld%c", dp[j][k], " \n"[k == o]);*/
    }
    ll ans = 0;
    for(int i = 0; i <= n - m; i++)
        add(ans, dp[i][pre[i]] * fac[n - pre[i]]);
    printf("%lld\n", ans);
}

void oC()
{
    ;
}

void oE()
{
    for(int i = 0; i < MAX_N; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    fac[0] = 1;
    for(int i = 1; i < MAX_N; i++)
        fac[i] = fac[i - 1] * i % P;
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j <= i; j++)
            A[i][j] = C[i][j] * fac[j] % P;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    oE();
    int T = 1;
    while(T--)
        oM(), oC();
    return 0;
}
