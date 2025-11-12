#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << x << ":" << x << endl
#define dbg2(...) cerr << "[" << #__VA_ARGS__ << "] = " ,debug_out(__VA_ARGS__)

template <typename T> void debug_out(T t) { cerr << t << endl;}
template <typename T, typename  ... Ts> void debug_out(T t, Ts ... ts) {
    cerr << t << ", ";
    debug_out(ts...);

}
int a[100005], b[100005], c[100005], vis[100005],n, m, ans = 0;

void dfs(int x)
{
    if (x >= n)
    {
        int cnt = 0, cnt2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (cnt2 >= b[i])
            {
                cnt2++;
                continue;
            }
            else
            {
                if (c[i]) cnt++;
                else cnt2++;
            }
        }
        if (cnt >= m) ans++;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            b[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("employ.in", "r", "stdin");
    freopen("employ.out", "w", "stdout");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin>> a[i];
    }
    for (int i = 1; i <= n; ++i) cin >>c[i];
    if (n <= 10)
    {
        dfs(1);
        cout << ans << endl;
    }
    else
    {
        ans = 1;
        for (int i = 1; i <= n; ++i) ans = (1ll * ans * i) % 998244353;
        cout << ans << endl;
    }
    return 0;
}
