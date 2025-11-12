#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9'){if(c == '-')f = -1;c = getchar();}
    while(c <= '9' && c >= '0'){x = x * 10 + c - '0', c = getchar();}
    return x * f;
}

inline void write(int x)
{
    if(x < 0)putchar('-'), x = -x;
    if(x <= 10)return (void)(putchar(x + '0'));
    write(x / 10), putchar(x % 10 + '0');
    return;
}

struct edge
{
    int u, v, w;
    bool operator <(const edge &x)const
    {
        return w < x.w;
    }
}e[2000010], e2[400100], e3[400010], ek[20][10010];

int cnt;

int f[1000010];

inline int getfa(int x)
{
    return (f[x] == x ? x : (f[x] = getfa(f[x])));
}

int c[20], a[20][10010];

int n, m, k;

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1;i <= m;i++)
    {
        int u = read(), v = read(), w = read();
        e[i] = {u, v, w};
    }
    sort(e + 1, e + m + 1);
    for(int i = 1;i <= k;i++)
    {
        c[i] = read();
        for(int j = 1;j <= n;j++)a[i][j] = read(), ek[i][j] = {n + i, j, a[i][j]};
        sort(ek[i] + 1, ek[i] + n + 1);
    }
    for(int i = 1;i <= n;i++)f[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i++)
    {
        if(getfa(e[i].u) == getfa(e[i].v))continue;
        e2[++cnt] = e[i];
        ans += e[i].w;
        f[getfa(e[i].u)] = getfa(e[i].v);
    }
    for(int i = 1;i <= cnt;i++)e[i] = e2[i];//, cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << "\n";
    for(int i = (1 << k) - 1;i >= 0;i--)
    {
        int cur = 0;
        int num = n;
        for(int j = 1;j <= k;j++)if(i & (1 << (j - 1)))cur += c[j], num++;
        for(int j = 1;j <= cnt;j++)e2[j] = e[j];
        int tot = n;
        for(int j = 1;j <= k;j++)
        {
            if((i & (1 << (j - 1))) == 0)continue;
            int lpos = 1, rpos = 1;
            int pos = 0;
            while(lpos <= tot && rpos <= n)
            {
                if(e2[lpos].w <= ek[j][rpos].w)e3[++pos] = e2[lpos++];
                else e3[++pos] = ek[j][rpos++];
            }
            while(lpos <= tot)e3[++pos] = e2[lpos++];
            while(rpos <= n)e3[++pos] = ek[j][rpos++];
            tot = pos;
            for(int l = 1;l <= pos;l++)e2[l] = e3[l];
        }
        // for(int j = 1;j <= tot;j++)cout << e2[j].u << ' ' << e2[j].v << ' ' << e2[j].w << "\n";
        for(int j = 1;j <= n + k;j++)f[j] = j;
        for(int j = 1;j <= tot && num > 1;j++)
        {
            if(getfa(e2[j].u) == getfa(e2[j].v))continue;
            cur += e2[j].w;
            num--;
            f[getfa(e2[j].u)] = getfa(e2[j].v);
            // if(cur >= ans)break;
        }
        // cout << i << ' ' << cur << "\n";
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}