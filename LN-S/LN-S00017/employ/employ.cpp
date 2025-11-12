#include<bits/stdc++.h>
using namespace std;
#define up(s, e, i) for (int i = (s); i <= (e); i++)
#define down(s, e, i) for (int i = (s); i >= (e); i--)
#define all(x) x.begin(), x.end()
#define endl '\n'

namespace Main
{
    const int N = 510, mod = 998244353;
    struct mdint
    {
        int value;
        mdint() { value = 0; }
        mdint(int x) : value((x % mod + mod) % mod){}
        mdint operator +=(const mdint &b)
        {
            value += b.value, value %= mod;
            return *this;
        }
        friend mdint operator +(mdint a, const mdint &b)
        {
            a += b;
            return a;
        }
    };
    int n, m;
    bool a[N];
    int c[N];
    mdint f[300010][20];
    bool check_A()
    {
        up(1, n, i) if (!a[i]) return 0;
        return 1;
    }
    void main()
    {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        cin >> n >> m;
        up(1, n, i) 
        {
            char c;
            cin >> c;
            a[i] = (c - '0');
        }
        up(1, n, i) cin >> c[i];

        if(n <= 18)
        {
            f[0][0] = 1;
            up(1, (1 << n) - 1, S) 
            {
                int now = __builtin_popcount(S);
                up(1, n, i) if (S & (1 << (i - 1)))
                {
                    up(0, n, j) f[S][j + (a[now] == 0 || j >= c[i])] += f[S ^ (1 << (i - 1))][j];
                }
            }
            mdint ans = 0;
            up(0, n - m, i) ans += f[(1 << n) - 1][i];
            cout << ans.value << endl;
            return;
        }
        if(m == 1)
        {
            int all = 1;
            up(1, n, i) all = 1ll * all * i % mod;
            int pre = 0;
            int ans = 1;
            up(1, n, i) if (a[i])
            {
                int cnt = 0;
                up(1, n, j) if (c[j] <= i - 1) cnt++;
                if(cnt - pre <= 0) return cout << all << endl, void();
                ans = 1ll * ans * (cnt - pre) % mod;
                pre++;
            }
            up(1, n - pre, i) ans = 1ll * ans * i % mod;
            cout << (all - ans + mod) % mod;
        }
    }
};

int main()
{
    Main::main();
    return 0;
}

// g++ employ.cpp -o employ -O2 -std=c++14 && ./employ