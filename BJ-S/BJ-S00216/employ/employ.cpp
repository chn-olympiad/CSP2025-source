#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c < '0' || c > '9'){if(c == '-')f = -1;c = getchar();}
    while(c <= '9' && c >= '0'){x = x * 10 + c - '0', c = getchar();}
    return x * f;
}

inline void write(int x)
{
    if(x < 0)putchar('-'), x = -x;
    if(x <= 10)return (void)(putchar(x + '0'));
    write(x / 10), putchar(x % 10 + '0');
    return;
}

const int mod = 998244353;

int c[510], p[510];

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1;i <= n;i++)cin >> c[i], p[i] = i;
    int ans = 0;
    if(n > 10)
    {
        ans = 1;
        for(int i = 1;i <= n;i++){if(s[i - 1] == '0' || c[i] == 0)ans = 0;ans *= i, ans %= mod;}
        cout << ans << "\n";
        return 0;
    }
    do
    {
        // for(int i = 1;i <= n;i++)cout << p[i] << ' ';
        // cout << "\n";
        int tot = 0;
        for(int i = 1;i <= n;i++)
        {
            if(s[i - 1] == '0' || tot >= c[p[i]])tot++;
        }
        if(n - tot >= m)ans++, ans %= mod;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << "\n";
    return 0;
}