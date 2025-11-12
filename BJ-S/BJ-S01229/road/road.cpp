#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1100002;

struct Edge
{
    int u,v; ll w;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
};

int tot;
int cnt;
int n,m,k;
int pre[MAXN];
Edge edges[MAXN];

int Find(int x)
{
    if(pre[x] == x)
        return x;
    return pre[x] = Find(pre[x]);
}

bool Join(int x,int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if(fx != fy)
    {
        cnt--;
        pre[fx] = fy;
        return true;
    }

    return false;
}

void Kruskal()
{
    cnt = n;
    for(int i = 1;i <= n;i++)
        pre[i] = i;
    
    ll ans = 0;
    sort(edges + 1,edges + m + 1);
    for(int i = 1;i <= m;i++)
    {
        Edge &cur = edges[i];
        if(Join(cur.u,cur.v))
        {
            ans += cur.w;
            if(cnt == 1)
                break;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    Kruskal();
    return 0;
}