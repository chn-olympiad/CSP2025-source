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
#define MAX_N 32768
#define MAX_M 2222222
#define MAX_K 22

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = false;do{c = getchar();if(c == '-')v = true;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c <= ' ' && c != EOF)c = getchar();return c;}

template<size_t N>
struct vset
{
    int f[N];
    vset() { memset(f, 255, sizeof(f)); }
    int fath(int x) { return f[x] < 0 ? x : f[x] = fath(f[x]); }
    bool merge(int x, int y)
    {
        x = fath(x), y = fath(y);
        if(x == y)
            return 0;
        if(f[x] > f[y]) // f[x] <= f[y]
            swap(x, y);
        f[x] += f[y], f[y] = x;
        return 1;
    }

    void clear(int n)
    {
        for(int i = 0; i <= n; i++)
            f[i] = -1;
    }
};

vset<MAX_N + MAX_K> st;
int n, m, k;

struct edge
{
    int u, v; // 1~n / n+1~n+k
    ll w;
};

inline bool operator < (const edge a, const edge b) { return a.w < b.w; }

edge seds[MAX_M];
edge eds[MAX_M + MAX_N * MAX_K];
ll c[MAX_K];

void oM()
{
    n = read();
    m = read();
    k = read();
    for(int i = 1; i <= m; i++)
    {
        int u = read();
        int v = read();
        ll w = read();
        seds[i] = (edge){u, v, w};
    }
    int tot = 0;
    sort(seds + 1, seds + m + 1);
    for(int i = 1; i <= m; i++)
        if(st.merge(seds[i].u, seds[i].v))
            eds[++tot] = seds[i];
    st.clear(n + k + 5);
    for(int i = 1; i <= k; i++)
    {
        c[i] = read();
        for(int j = 1; j <= n; j++)
        {
            ll w = read();
            eds[++tot] = (edge){j, i + n, w};
        }
    }
    sort(eds + 1, eds + tot + 1); // tot = n - 1 + nk
    ll ans = inf;
    for(int s = 0; s < (1 << (k + 1)); s += 2)
    {
        ll d = 0;
        for(int i = 1; i <= k; i++)
            if((s >> i) & 1)
                d += c[i];
        for(int i = 1; i <= tot; i++)
            if(((eds[i].u <= n || ((s >> (eds[i].u - n)) & 1)) && (eds[i].v <= n || ((s >> (eds[i].v - n)) & 1))) && st.merge(eds[i].u, eds[i].v))
                d += eds[i].w;
        ans = min(ans, d);
        st.clear(n + k + 5);
    }
    printf("%lld\n", ans);
}

void oC()
{
    ;
}

void oE()
{
    ;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    oE();
    int T = 1;
    while(T--)
        oM(), oC();
    return 0;
}
