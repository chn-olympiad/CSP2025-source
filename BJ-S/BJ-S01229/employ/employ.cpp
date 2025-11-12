#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 502;
const ll MOD = 998244353;

ll ans;
int n,m;
string s;
int c[MAXN];
int p[MAXN];
int sums[MAXN];

bool vis[MAXN];
void Dfs(int step)
{
    if(step == n + 1)
    {
        int loses = 0;
        for(int i = 1;i <= n;i++)
        {
            if(loses >= c[p[i]])
            {
                loses++;
                continue;
            }
            if(s[i] == '0')
                loses++;
        }

        if(n - loses >= m)
        {
            ans++;
            if(ans >= MOD)
                ans -= MOD;
        }

        return;
    }

    for(int i = 1;i <= n;i++)
    {
        if(vis[i])
            continue;
        vis[i] = true;
        p[step] = i;
        Dfs(step + 1);
        p[step] = 0;
        vis[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >> m >> s;s = ' ' + s;
    for(int i = 1;i <= n;i++)
        cin >> c[i];
    
    if(m == n)
    {
        for(int i = 1;i <= n;i++)
        {
            if(s[i] == '0')
            {
                cout << "0\n";
                return 0;
            }
        }

        for(int i = 1;i <= n;i++)
        {
            if(c[i] == 0)
            {
                cout << "0\n";
                return 0;
            }
        }

        ll res = 1;
        for(ll i = 1;i <= n;i++)
            res = (res * i) % MOD;
        cout << res << '\n';
        return 0;
    }

    if(n <= 18)
    {
        Dfs(1);
        cout << ans << '\n';
        return 0;
    }

    cout << 0 << '\n';
    return 0;
}