#include <iostream>
#include <queue>
#include <algorithm>
typedef long long ll;
const ll N = 1e3+5,M = 2e6+5,K = 15,lim = 1e18;

struct node
{
    ll u,v,w;
}p[M];
ll a[N];

ll n,m,k,dis[N][N],pre[N][N],kd[K][N],c[K],choose[K],choose_l;
bool tp1;

ll read()
{
    char cc = getchar();
    ll ch=0;
    while(cc<'0'||cc>'9') cc = getchar();
    while(cc>='0'&&cc<='9')
    {
        ch = (ch<<3)+(ch<<1)+cc-'0';
        cc = getchar();
    }
    return ch;
}

ll gets(ll x)
{
    if(a[x]!=x) a[x] = gets(a[x]);
    return a[x];
}

bool cmp(node x,node y){return x.w < y.w;}

ll Kruskal()
{
    for(ll i=1;i<=choose_l;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll h=j+1;h<=n;h++)
            {
                dis[j][h] = std::min(dis[j][h],kd[choose[i]][j]+kd[choose[i]][h]+c[choose[i]]);
            }
        }
    }
    ll length = 0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(dis[i][j]==lim) continue;
            p[++length].u = i;
            p[length].v = j;
            p[length].w = dis[i][j];
        }
    }
    for(ll i=1;i<=n;i++) a[i] = i;
    std::sort(p+1,p+1+length,cmp);
    ll cnt = 0,ans = 0;
    for(ll i=1;i<=length;i++)
    {
        if(cnt==n-1) break;
        ll dx = gets(p[i].u),dy = gets(p[i].v);
        if(dx==dy) continue;
        if(dx>dy) std::swap(dx,dy);
        a[dy] = dx;
        ans += p[i].w;
        ++cnt;
    }
    return ans;
}

void solve()
{
    for(ll i=1;i<=m;i++)
    {
        p[i].u = read();
        p[i].v = read();
        p[i].w = read();
    }
    for(ll i=1;i<=n;i++) a[i] = i;
    std::sort(p+1,p+1+m,cmp);
    ll cnt = 0,ans = 0;
    for(ll i=1;i<=m;i++)
    {
        if(cnt==n-1) break;
        ll dx = gets(p[i].u),dy = gets(p[i].v);
        if(dx==dy) continue;
        if(dx>dy) std::swap(dx,dy);
        a[dy] = dx;
        ans += p[i].w;
        ++cnt;
    }
    std::cout << ans << '\n';
}

void solve1()
{
    choose_l = k;
    for(ll i=1;i<=k;i++) choose[i] = i;
    std::cout << Kruskal() << '\n';
}

void solve2()
{
    ll ans = lim;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++) pre[i][j] = dis[i][j];
    }
    for(ll i=0;i<(1<<k);i++)
    {
        choose_l = 0;
        for(ll j=1;j<=k;j++) if((i>>(j-1))&1) choose[++choose_l] = j;
        ans = std::min(ans,Kruskal());
        for(ll j=1;j<=n;j++)
        {
            for(ll h=j+1;h<=n;h++) dis[j][h] = pre[j][h];
        }
    }
    std::cout << ans << '\n';
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    n = read(),m = read(),k = read();
    if(k==0)
    {
        solve();
        return 0;
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            dis[i][j] = dis[j][i] = lim;
        }
    }
    for(ll i=1,x,y;i<=m;i++)
    {
        x = read(),y = read();
        dis[x][y] = dis[y][x] = read();
    }
    for(ll i=1;i<=k;i++)
    {
        c[i] = read();
        if(c[i]>0) tp1 = 1;
        for(ll j=1;j<=n;j++) kd[i][j] = read();
    }
    if(!tp1)
    {
        solve1();
        return 0;
    }
    solve2();
    return 0;
}
