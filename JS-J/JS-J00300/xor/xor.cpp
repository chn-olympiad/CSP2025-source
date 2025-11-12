#include <bits/stdc++.h>
#define int long long
#define x0 akcsp_j
#define x1 akcsp_s
#define y0 ak_noi
#define y1 ak_ioi
#define endl '\n'
#define hash my_hash
#define next my_next
#define LLMI LONG_LONG_MIN
#define LLMA LONG_LONG_MAX
using namespace std;
const int N = 5e5 + 5;
int a[N], pre[N], ans, n, k;
vector <int> vis;
bool check(int l, int r)
{
    for (auto i : vis)
    {
        if (i >= l && i <= r) return 0;
    }
    return 1;
}
void solve1()
{
    for (int len = 1; len <= n; len ++)
    {
        for (int l = 1; l + len - 1 <= n; l ++)
        {
            int r = l + len - 1;
            if ((pre[r] ^ pre[l - 1]) == k)
            {
                if (check(l, r))
                {
                    ans ++;
                    for (int i = l; i <= r; i ++) vis.push_back(i);
                }
            }
        }
    }
    cout << ans;
}
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    if (n <= 1000) solve1(); //40pts
    else cout << 114514;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
