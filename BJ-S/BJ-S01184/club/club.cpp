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
#define MAX_N 522222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = false;do{c = getchar();if(c == '-')v = true;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c <= ' ' && c != EOF)c = getchar();return c;}

int n;
ll a[MAX_N][3];
int v[MAX_N];
ll b[MAX_N];

void oM()
{
    n = read();
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++)
            a[i][j] = read();
    ll ans = 0;
    int chs[3] = {0, 0, 0};
    for(int i = 1; i <= n; i++)
    {
        ll d = a[i][0];
        int t = 0;
        for(int j = 1; j < 3; j++)
            if(a[i][j] > d)
                d = a[i][j], t = j;
        ans += d;
        chs[v[i] = t]++;
    }
    int t = 0;
    for(int j = 1; j < 3; j++)
        if(chs[j] > chs[t])
            t = j;
    if(chs[t] * 2 <= n)
    {
        printf("%lld\n", ans);
        return;
    }
    int m = 0;
    for(int i = 1; i <= n; i++)
        if(v[i] == t)
        {
            ll mx2 = -1;
            for(int j = 0; j < 3; j++)
                if(j != t)
                    mx2 = max(mx2, a[i][j]);
            b[++m] = a[i][t] - mx2;
        }
    sort(b + 1, b + m + 1);
    int k = m - n / 2;
    for(int i = 1; i <= k; i++)
        ans -= b[i];
    printf("%lld\n", ans);
}

void oC()
{
    for(int i = 0; i <= n + 3; i++)
        a[i][0] = a[i][1] = a[i][2] = v[i] = b[i] = 0;
}

void oE()
{
    ;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    oE();
    int T = read();
    while(T--)
        oM(), oC();
    return 0;
}
