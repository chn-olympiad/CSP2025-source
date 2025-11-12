#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int peo[N][3];
struct ddd
{
    int maxx, a, b, c;
} dp[N][3];
void solve()
{
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> peo[i][0] >> peo[i][1] >> peo[i][2];
    int lim = n / 2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int maxx = 0, id = 0;
            for(int k = 0; k < 3; k++)
            {
                // dp[i][j].a = dp[i - 1][k].a, dp[i][j].b = dp[i - 1][k].b, dp[i][j].c = dp[i - 1][k].c;
                if((j == 0 && dp[i - 1][k].a == lim) || (j == 1 && dp[i - 1][k].b == lim) || (j == 2 && dp[i - 1][k].c == lim)) // 满员了, 不能再加人了
                    continue;
                if(dp[i - 1][k].maxx > maxx) // 决定将这个人扔到哪
                    maxx = dp[i - 1][k].maxx, id = k;
            }
            dp[i][j].maxx = dp[i - 1][id].maxx + peo[i][j];
            dp[i][j].a = dp[i - 1][id].a, dp[i][j].b = dp[i - 1][id].b, dp[i][j].c = dp[i - 1][id].c;
            if(j == 0)
                dp[i][j].a++;
            if(j == 1)
                dp[i][j].b++;
            if(j == 2)
                dp[i][j].c++;
        }
    }
    cout << max({dp[n][0].maxx, dp[n][1].maxx, dp[n][2].maxx}) << '\n';
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
/*
 freopen("club.in", "w", stdin);
 freopen("club.out", "r", stdout);
 Please use UTF-8 open it
*/

/*
这场考试结束之后就正式告别OI了(90%), 其实8月就AFO了(因为文化课太差了, 还好是在初二)
2个月没写代码(补文化课去了), 已经不知道代码该怎么写了, 题该怎么做了
如果是刚退役的时候做肯定还能做到更好
但愿这次能拿个3=
经典小样例全过, 大样例过一半(T1是每个样例对一半, 谁发明的多测!!!)
T1, T2做法全是假的, T3, T4甚至不想骗分
希望能多给我一些分
也祝那些还在役的同学们能够早日拿省一吧
希望有人看到这段话能帮我看一下T1, T2的代码该怎么改

T2:
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
struct edge
{ 
    int u, v, w;
};
int fa[N], si[N];
void init(int n)
{
    for(int i = 1; i <= n; i++)
        fa[i] = i, si[i] = 1;
}
int find(int n)
{
    if(fa[n] != n) 
        return fa[n] = find(fa[n]);
    return n;
}
void merge(int u, int v)
{
    int fu = find(u), fv = find(v);
    if(fu == fv)
        return;
    fa[fu] = fa[fv];
    si[fv] += si[fu];
}
bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
ll ans = 0;
bool vis[N + 20];
bool used[N + 20];
int coin[N];
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<edge> G;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    init(n + k);
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w});
    }
    si[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        coin[i + n] = c, si[i + n] = 0;
        G.push_back({0, i + n, c});
        for(int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            G.push_back({j, i + n, w});
        }
    }
    sort(G.begin(), G.end(), cmp);
    for(auto val : G)
    {
        int u = val.u, v = val.v, w = val.w;
        // cerr << u << " " << v << " " << w << '\n';
        int fu = find(u), fv = find(v);
        if((u == 0 && v > n) || (v == 0 && u > n)) 
            vis[v] = 1;
        if((u <= n && v > n && vis[v] == 0) || (v <= n && u > n && vis[u] == 0))
            continue;
        if(fu != fv) // 不在同一连通块
        {
//        	cout << u << " " << v << '\n';
            if((u <= n && v > n && u != 0) || (v <= n && u > n && v != 0))
                used[u] = 1, used[v] = 1;
            merge(fu, fv);
            ans += w;
        }
        if(si[find(1)] == n)
            break;
    }
    cout << ans;
    return 0;
}


Luogu:kunkunge(基本上没在用了), 其他OJ就懒得给了, QQ写在Luogu简介上的
还有,三角洲真好玩(bushi)ID:kunkunge(周5晚上上线, 小唐人一个)

一个还有5分钟就正式告别OI的人
*/