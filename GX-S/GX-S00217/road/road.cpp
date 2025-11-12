#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll SUP = (ll)1<<62;
const int MAXN = 10020;
const int MAXM = 1000010;
int n,m,k;
ll c[20];
bitset<20> tmp;
ll ans = SUP;
int fa[MAXN];

int fd(int x)
{
    if (x == fa[x]) return x;
    else return x = fd(fa[x]);
}

void mg(int x,int y)
{
    x = fd(x),y = fd(y);
    fa[x] = y;
}

struct edge
{
    int s,t;
    ll w;

    bool operator<(const edge & x)const
    {
        return w < x.w;
    }
}e[MAXM<<1];
int ecnt;

void addedge(int u,int v,int w)
{
    e[++ecnt].w = w,e[ecnt].s = u,e[ecnt].t = v;
}

ll getans(int x)
{
    ll res = 0;
    for (int i=1;i<=n+k;i++) fa[i] = i;
    tmp = x;
    int cnt = n + tmp.count();
    //for (int i=0;i<k;i++) cout << tmp[i] << " ";
    //cout << endl;
    for (int i=0;i<k;i++) if (tmp[i] == 1) res += c[i+1];
    //cout << res << endl;

    for (int i=1;i<=ecnt;i++)
    {
        if (e[i].s > n && tmp[e[i].s - n - 1] == 0) continue;
        if (fd(e[i].s) == fd(e[i].t)) continue;
        mg(e[i].s,e[i].t);
        res += e[i].w;
        cnt --;
        if (cnt == 1) break;
    }

    return res;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        addedge(u,v,w);
    }
    for (int i=1;i<=k;i++)
    {
        cin >> c[i];
        for (int j=1;j<=n;j++)
        {
            ll w;
            cin >> w;
            addedge(n+i,j,w);
        }
    }
    sort(e+1,e+ecnt+1);

    for (int i=0;i<(1<<k);i++)
    {
        ans = min(getans(i),ans);
    }

    cout << ans << endl;



    return 0;
}
