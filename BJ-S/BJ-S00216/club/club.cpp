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

int a[100010][4], n;

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while(T--)
    {
        n = read();
        int tot[4] = {0, 0, 0, 0};
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])tot[1]++, ans += a[i][1];
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])tot[2]++, ans += a[i][2];
            else tot[3]++, ans += a[i][3];
        }
        int k = 0;
        if(tot[1] > n / 2)k = 1;
        if(tot[2] > n / 2)k = 2;
        if(tot[3] > n / 2)k = 3;
        if(!k)
        {
            cout << ans << "\n";
            continue;
        }
        vector <int> v;
        for(int i = 1;i <= n;i++)
        {
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && k == 1)v.push_back(a[i][1] - max(a[i][2], a[i][3]));
            else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3] && k == 2)v.push_back(a[i][2] - max(a[i][1], a[i][3]));
            else if(a[i][3] >= a[i][1] && a[i][3] >= a[i][2] && k == 3)v.push_back(a[i][3] - max(a[i][1], a[i][2]));
        }
        sort(v.begin(), v.end());
        for(int i = 0;i < tot[k] - (n / 2);i++)ans -= v[i];
        cout << ans << '\n';
    }
    return 0;
}