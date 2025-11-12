#include <iostream>
using namespace std;

int n, m, a[505], mod = 998244353, ans, l, len, b[505], d[505], num[505], sum;
string s;
bool f[20];

void dfs(int k, int c)
{
    if (k > n)
    {
        ++ans;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (f[i]) continue;
        int t = c;
        if (s[k-1] == '0' || a[i] <= c) ++t;
        if (t > n - m) continue;
        f[i] = true;
        dfs(k+1, t);
        f[i] = false;
    }
}

int get()
{
    int mul = 1, cnt2 = 0;
    for (int i = l; i >= 1; --i) mul = (mul * (d[b[i]-i] - cnt2)) % mod;
    return mul;
}

void dfs2(int k, int cnt)
{
    if (k > len)
    {
        ans += get();
        return;
    }
    if (cnt + len - k + 1 > m) dfs(k+1, cnt);
    b[++l] = num[k];
    dfs(k+1, cnt+1);
    --l;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ++d[a[i]];
        sum += s[i-1] - '0';
    }
    for (int i = n; i >= 0; --i) d[i] += d[i+1];
    if (n <= 10)
    {
        dfs(1, 0);
        cout << ans;
    }
    else if (sum <= 18)
    {
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == '1')
                num[++len] = i;
        dfs2(1, 0);
        cout << ans;
    }
    else
    {
        long long mul = 1;
        for (int i = 1; i <= n; ++i) mul = (mul * i) % mod;
        cout << mul;
    }
    return 0;
}
