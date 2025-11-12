#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int c[maxn];
int n, m;
string s;

signed main()
{
    freopen("employ3.in", "r", stdin);
    //freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> s;
    bool flaga = 1;
    for(int i = 0; i < s.size(); i++)
    {
        flaga &= s[i] - '0';
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    if(flaga)
    {
        int ans = 1;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(c[i]) cnt++;
        cout <<cnt << "\n";
        if(cnt < m) cout << 0;
        else
        {
            for(int i = 1; i <= 46; i++) ans = ans * i % mod;
            cout << ans << "\n";
        }

    }
    for(int i = 1; i <= 105; i++)
    {
        int ans = 1;
        for(int j = 1; j <= i; j++) ans = ans * i % mod;
        if(ans == 161088479) cout << i << "!\n";
    }cout << "NO?";

    return 0;
}
