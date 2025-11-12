#include<bits/stdc++.h>
using namespace std;
#define up(s, e, i) for (int i = (s); i <= (e); i++)
#define down(s, e, i) for (int i = (s); i >= (e); i--)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define int long long
namespace Main
{
    const int N = 10050, M = 1000010, inf = 0x3f3f3f3f3f3f3f3f;
    int n, m, k;
    int c[11];
    pair<int, int> a[11][N];
    int pos[11];
    struct edge
    {
        int u, v, w;
        bool operator <(edge b) const 
        {
            return w < b.w;
        }
    } e[M], e2[N];
    int tot;
    struct bcj
    {
        int fa[N], siz[N];
        void init()
        {
            up(1, n + k, i) fa[i] = i, siz[i] = 1;
        }
        int find(int x)
        {
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        }
        void merge(int x, int y)
        {
            x = find(x), y = find(y);
            if(x == y) return;
            if(siz[x] > siz[y]) swap(x, y);
            fa[x] = y, siz[y] += siz[x];
        }
    } b;
    void main()
    {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        cin >> n >> m >> k;
        up(1, m, i)
        {
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        sort(e + 1, e + 1 + m);
        b.init();
        up(1, m, i) if (b.find(e[i].u) != b.find(e[i].v))
        {
            e2[++tot] = e[i];
            b.merge(e[i].u, e[i].v);
        }
        up(1, k, i)
        {
            cin >> c[i];
            up(1, n, j) cin >> a[i][j].first, a[i][j].second = j;
            sort(a[i] + 1, a[i] + 1 + n);
        }
        int mn = inf;
        up(0, (1 << k) - 1, S)
        {
            b.init();
            int ans = 0;
            int ecnt = 0;
            vector<int> vec;
            up(1, k, i) if (S & (1 << (i - 1))) ans += c[i], vec.push_back(i);
            auto adde = [&](edge e)
            {
                if (b.find(e.u) == b.find(e.v)) return;
                ans += e.w;
                b.merge(e.u, e.v);
                ecnt++;
            };
            vector<edge> nw;
            up(1, k, i) pos[i] = 1;
            int p = 1;
            while (1)
            {
                edge e = {0, 0, inf};
                int ch = 0;
                for(auto i: vec) if (pos[i] <= n)
                {
                    if(e.w > a[i][pos[i]].first)
                    {
                        e = {i + n, a[i][pos[i]].second, a[i][pos[i]].first};
                        ch = i;
                    }
                }
                while(p <= tot && e2[p].w < e.w) 
                {
                    adde(e2[p]), p++;
                    if(ecnt == n + vec.size() - 1) break;
                }
                if(e.w == inf) break;
                adde(e);
                pos[ch]++;
                if(ecnt == n + vec.size() - 1) break;
                if(ans > mn) break;
            }
            mn = min(mn, ans);
        }
        cout << mn << endl;
    }
};

signed main()
{
    Main::main();
    return 0;
}

// g++ road.cpp -o road -O2 -std=c++14 && ./road