#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
struct edge
{
    int a,b,c;
    bool is;
    bool operator <(const edge r)const
    {
        return c < r.c;
    }
}edges[N];
int p[N];
int buildmon[N];
bool monpay[N];
int finds(int x)
{
    if (p[x] != x)
    {
        p[x] = finds(p[x]);
    }
    return p[x];
}

int n,m,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i ++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {a,b,c,0};
        edges[i] = {b,a,c,0};
    }
    for (int i = 1;i <= n + k;i ++)
    {
        p[i] = i;
    }
    int nxro = m;
    for (int i = 1;i <= k;i ++)
    {
        cin >> buildmon[n + i];
        for (int j = 1;j <= n;j ++)
        {
            int c;
            cin >> c;
            edges[++nxro] = {n + i,j,c,1};
            edges[++nxro] = {j,n + i,c,1};
        }
    }
    int res = 0;
    sort(edges + 1,edges + 1 + nxro);
    for (int i = 1;i <= nxro;i ++)
    {
        int a = edges[i].a,b = edges[i].b,c = edges[i].c;
        bool flag = edges[i].is;
        int pa = finds(a),pb = finds(b);
        if (pa != pb)
        {
            if(flag == 1)
            {
                if (!monpay[a])
                {
                    res += buildmon[a];
                    //cout << a << ':' << buildmon[a] << endl;
                    monpay[a] = true;
                }
                if(!monpay[b])
                {
                    res += buildmon[b];
                    //cout << b << ':' << buildmon[b] << endl;
                    monpay[b] = true;
                }
            }
            //cout << a << ' ' << b << endl;
            res += c;
            p[pa] = pb;
        }
    }
    cout << res << endl;
    return 0;
}
