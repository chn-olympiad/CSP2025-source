#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 10, MR = 2e6 + 10;
struct Edge
{
    int u, v, w, id;
    bool operator <(const Edge &p) const
    {
        if(w != p.w) return w > p.w;
        return id > p.id;
        /*if(u != p.u) return u > p.u;
        return v > p.v;*/
    }
} e[MR], f[MR];
priority_queue <Edge> pqk;
int fa[NR + 100], m, n, k, c[NR + 100], nm;
long long finans, cusg;
bool inmst[MR], usg[NR + 100];

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

long long krsk()
{
    for(int i = 1; i <= m; i++) pqk.push(e[i]);
    for(int i = 1; i <= n; i++) fa[i] = i;
    long long tans = 0;
    while(!pqk.empty())
    {
        Edge cur = pqk.top();
        pqk.pop();
        if(find(cur.u) != find(cur.v))
        {
            tans += cur.w;
            fa[fa[cur.u]] = fa[cur.v];
            inmst[cur.id] = 1;
        }
    }
    return tans;
}

long long krsk2()
{
    for(int i = 1; i <= nm; i++) if(f[i].id <= n || usg[f[i].id]) pqk.push(f[i]);
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    long long tans = 0;
    while(!pqk.empty())
    {
        Edge cur = pqk.top();
        pqk.pop();
        if(find(cur.u) != find(cur.v))
        {
            tans += cur.w;
            fa[fa[cur.u]] = fa[cur.v];
        }
    }
    return tans;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].id = i;
    }
    //cout << "finput1\n";
    finans = krsk();
    for(int i = 1; i <= m; i++)
    {
        if(inmst[i])
        {
            f[++nm] = e[i];
            f[nm].id = e[i].u;
        }
    }
    //cout << "finkrk\n";
    //nm = m + k * n;
    for(int i = 1; i <= k; i++)
    {
        cin >> c[n + i];
        usg[n + i] = 1;
        cusg += c[n + i];
        for(int j = 1; j <= n; j++)
        {
            int aij;
            cin >> aij;
            f[++nm] = (Edge){n + i, j, aij, n + i};
            //e[m + (i - 1) * n + j] = (Edge){n + i, j, aij, m + (i - 1) * n + j};
        }
    }
    //cout << "finput2\n";
    long long minpos, minn;
    for(int tms = k; tms >= 1; tms--)
    {
        //cout << "strkrk " << tms << "\n";
        finans = min(finans, krsk2() + cusg);
        //cout << "finkrk " << tms << "\n";
        minpos = minn = 0x3f3f3f3f3f3f3f3f;//asdasfgda
        for(int i = n + 1; i <= n + k; i++)
        {
            if(!usg[i]) continue;
            usg[i] = 0;
            //cout << "strkrk " << tms << " " << i << "\n";
            long long tval = krsk2() + cusg - c[i];
            //cout << "finkrk " << tms << " " << tval << " " << i << "\n";
            if(tval < minn)
            {
                minn = tval;
                minpos = i;
            }
            usg[i] = 1;
        }
        //cout << "extkrk " << tms << " " << minpos << "\n";
        usg[minpos] = 0;
        //cout << "ASdfd " << tms << "\n";
        cusg -= c[minpos];
        //cout << "sdds " << tms << '\n';
    }
    cout << finans << "\n";
    return 0;
}