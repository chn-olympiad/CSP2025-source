#include <bits/stdc++.h>
using namespace std;

int db[10005],n,m,k;

bool check()
{
    for(int i = 1;i < n;i++)
    {
        if(db[i] != db[i + 1])return false;
    }
    return true;
}

int findd(int x)
{
    if(db[x] == x)
    {
        return x;
    }
    else return db[x] = findd(db[x]);
}

void join(int x,int y)
{
    int fx = findd(x),fy = findd(y);
    if(fx != fy)
    {
        db[fx] = fy;
        findd(x);
    }
}

int c[10005];

struct edge{
    int u,v,w;
}e[10000005];

bool cmp(edge x,edge y)
{
    return x.w < y.w;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m>> k;
    for(int i = 1;i <= m;i++)
    {
        int u,v,W;
        cin >> u >> v >> W;
        e[i].u = u;
        e[i].v = v;
        e[i].w = W;
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        int id =i + n;
        for(int j = 1;j <= n;j++)
        {
            int W;
            cin >> W;
            e[++m].u = j;
            e[m].v = id;
            e[m].w = W;
        }
    }
    for(int i = 1;i <= n + k;i++) db[i] = i;
    sort(e + 1,e + m + 1,cmp);
    int cnt = 0,ans = 0;
    for(int i = 1;i <= m;i++)
    {
        if(cnt >= n - 1)
        {
            if(check() || k == 0)break;
        }
        if(findd(e[i].u) != findd(e[i].v))
        {
            join(e[i].u,e[i].v);
            ans += e[i].w;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
