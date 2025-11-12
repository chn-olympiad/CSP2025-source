#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e4;
int fa[N + 25];
struct Node{
    int u,v,w;
} e[N * 200 + 5];
vector<pair<int,int> > a[N + 5];
int c[15];
pair<int,int> b[15][N + 5];
int pos[15];
Node ed[N * 200];
int tmp[N + 5];
int n,m,k;

int find(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
bool cmp(Node a,Node b)
{
    return a.w < b.w;
}
int kruskal(int nn,int mm,Node ee[])
{
    for(int i = 1;i <= nn;i++) fa[i] = i;
    int ans = 0,cnt = 0;
    for(int i = 1;i <= mm;i++)
    {
        int u = ee[i].u,v = ee[i].v,w = ee[i].w;
        int fu = find(u),fv = find(v);
        //cout << u << ' ' << v << ' ' << w << ' ' << fu << ' ' << fv << endl;
        if(fu == fv) continue;
        fa[fu] = fv;
        cnt++;
        ans += w;
        if(cnt == nn - 1) break;
    }
    return ans;
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
        e[i] = {u,v,w};
    }
    bool flag = 1;
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        if(c[i]) flag = 0;
        bool t = 0;
        for(int j = 1;j <= n;j++)
        {
            cin >> b[i][j].first;
            b[i][j].second = j;
            if(b[i][j].first == 0)
            {
                pos[i] = j;
                t = 1;
            }
        }
        flag = flag && t;
    }
    sort(e + 1,e + 1 + m,cmp);
    if(flag)
    {
        for(int i = 1;i <= k;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(j == pos[i]) continue;
                e[++m] = {pos[i],j,b[i][j].first};
            }
        }
        cout << kruskal(n,m,e);
        return 0;
    }/*
    for(int i = 1;i <= k;i++)
    {
        sort(b[i] + 1,b[i] + 1 + n);
        b[n + 1].first = 9e18;
    }*/
    int ans = 9e18;
    for(int p = 0;p < (1 << k);p++)
    {
        int nn = n,mm = m,res = 0;
        for(int i = 1;i <= m;i++) ed[i] = e[i];
        for(int i = k;i >= 1;i--)
        {
            if(p & 1)
            {
                //cout << (p & 1) << ' ';
                res += c[i];
                nn++;
                /*
                int l = 1,r = 1,len = 0;
                while(1)
                {
                    if(b[i][l].first < ed[r].w)
                    {
                        tmp[++len] = {nn,b[i][l].second,b[i][l].first};
                        l++;
                    }
                    else
                    {
                        tmp[++len] = ed[r];
                        r++;
                    }
                    if(len >= n) break;
                }*/
                //for(int i = 1;i <= n;i++) ed[i] = tmp[i];
                for(int j = 1;j <= n;j++)
                {
                    ed[++mm] = {nn,b[i][j].second,b[i][j].first};
                }
            }
        }
        //cout << endl;
        //cout << nn << ' ' << mm << endl;
        sort(ed + 1,ed + 1 + mm,cmp);
        /*
        for(int i = 1;i <= mm;i++)
        {
            cout << ed[i].u << ' ' << ed[i].v <<' ' << ed[i].w << endl;
        }
        cout << kruskal(nn,mm,ed);
        cout << endl;*/
        ans = min(ans,res + kruskal(nn,mm,ed));
    }
    cout << ans;
    return 0;
}
