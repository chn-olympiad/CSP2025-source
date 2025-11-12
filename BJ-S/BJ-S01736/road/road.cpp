#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e4 + 5;
const int M = 2e6 + 5;
const int L = 13;

int n,m,mm,k,c[L],a[L][N],f[N],vis[L];
long long ans = 9e18;

struct edge
{
    int u,v,w;
} ee[M],e[M];

inline bool cmp(edge a,edge b)
{
    return a.w < b.w;
}

inline int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}

inline void calc(int x)
{
    long long res = 0; int cnt = 0; for(int i=1;i<=n+k;i++) f[i] = i;
    m = mm; for(register int i=1;i<=m;i++) e[i] = ee[i];
    for(register int i=1;i<=k;i++) vis[i] = 0;
    for(register int i=1;i<=k;i++) if((x >> (i - 1)) & 1) vis[i] = 1, res += c[i];
    // for(int i=1;i<=k;i++) cout << vis[i] << " ";
    for(int i=1;i<=k;i++)
        if(vis[i])
        {
            for(register int j=1;j<=n;j++) e[++m] = {j,n+i,a[i][j]};
        }
    sort(e+1,e+m+1,cmp);
    for(register int i=1;i<=m;i++)
    {
        int fx = find(e[i].u), fy = find(e[i].v);
        if(fx != fy)
        {
            f[fx] = fy;
            res += e[i].w;
            cnt++;
        }
        if(cnt >= n + k - 1) break;
    }
    ans = min(ans,res);
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k; mm = m;
    for(register int i=1;i<=m;i++) cin >> ee[i].u >> ee[i].v >> ee[i].w;
    for(register int i=1;i<=k;i++)
    {
        cin >> c[i];
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    bool flag = 1;
    for(register int i=1;i<=k;i++) if(c[i] != 0) {flag = 0; break;}
    if(!flag) for(int i=0;i<(1<<k);i++) calc(i);
    else
    {
        // cout << "!!!" << endl;
        calc((1<<k)-1);
    }
    cout << ans << '\n';
    return 0;
}
