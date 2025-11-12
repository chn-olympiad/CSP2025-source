#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e4 + 100;
using it2 = array<int, 2>;

int n, m, k, ans = 0x1145141919810CCFull;
int fat[N], c[N], a[11][N], all;
struct edge
{
    int u, v, w;
    edge(const int &_u = 0, const int &_v = 0, const int &_w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &rhs) const
    {
        return w < rhs.w;
    }
};
vector<edge> e, olde;

int find(int x)
{
    return fat[x] == x ? x : (fat[x] = find(fat[x]));
}

inline int solve()
{
    iota(fat + 1, fat + n + k + 3, 1);
    int res = 0, cnt = 0, u, v, w, fu, fv;
    sort(e.begin(), e.end());
    for (edge &ed : e)
    {
        u = ed.u, v = ed.v, w = ed.w;
        fu = find(u), fv = find(v);
        if (fu != fv)
        {
            fat[fu] = fv;
            ++cnt;
            res += w;
        }
        if (cnt == all - 1)
        {
            return res;
        }
    }
    return res;
}

signed main()
{
    if (1)
    {
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
    }
    cin.tie(0)->sync_with_stdio(0), cout << fixed << setprecision(10);

    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w, olde.emplace_back(u, v, w);
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> c[i];
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    e = olde;
    ans = solve();
    for (int s = (1 << k) - 1, T = 1; s >= 1; --s, ++T)
    {
        if (clock() * (T + 1.2) / T > CLOCKS_PER_SEC)
        {
            break;
        }
        int sum = 0;
        all = n + __builtin_popcount(s);
        for (int i = 1; i <= k; ++i)
        {
            if (s >> (i - 1) & 1)
            {
                sum += c[i];
            }
        }
        if (sum >= ans)
        {
            continue;
        }
        e = olde;
        for (int i = 1; i <= k; ++i)
        {
            if (s >> (i - 1) & 1)
            {
                for (int j = 1; j <= n; ++j)
                {
                    e.emplace_back(n + i, j, a[i][j]);
                }
            }
        }
        ans = min(ans, solve() + sum);
    }
    cout << ans << '\n';
}
/*
就这样吧，天已经黑了，还没想出 T2。
前些天模拟赛打得也很烂，就这样失败了吗。
仍有人还在疯狂敲击键盘，也有像我左边这位 TMD 一直在发出噪音。

打出了 T1，没有红温，接受自己的平庸，接受自己的不幸，就算是没有 1=（其实应该有吧），也只是一次。

我现在才初三，有很多大事，AlBU（铝硼铀），中考，都是很重要的。

这只是一次 CSP-S，T1 放返回贪心的出题人的妈妈一定很多，T2 又是神秘 MST，昨天信心赛有两道也只做了一道。

现在只有：100+48+15+8=171，还不如去年 220。

曾经 S1= 的我去哪了，做的那么多道题又有什么用，每次看题解都只是试图掩盖自己的无知，tarjan、SAM、网络流至今不想学，只会随机化骗分的我也接连失利。

算了，并不是很糟，学过的返回贪心不也做出来了吗，只是自己太菜罢了，我的同学肯定都能进 WC，高年级的学长都可以 AK，只有我无助地跟 T1 大战，跟 T2 大战。

就这样吧，坦然面对，没有什么好挂分的，就是自己菜，无数次面对数学题指挥发呆，只会在听完讲题后来一句我怎么没想到，之所以我打挂是理所应当的。

欠了什么，什么就会找回来，为了跳过思考而看题解的我自然只会发呆，不刻苦练题的我只会对不上脑电波，对着题解代码调试的我只会跟调试大战。

哎，只能在这个最紧张最重要的时候审判自己了。

-- luogu uid: 818165.
*/
