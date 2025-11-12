#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
string s;
int c[510];
int cnt;
int f[510];

void dfs(int now,int full)
{
    if(now == n+1)
    {
        int no = 0,no2 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(no >= c[f[i]])
            {
                no2++;
                continue;
            }
            if(s[i] == '0') no++;
        }
        if(n - no2 - no < m) return;
        cnt++;
        return;
    }
    f[now] = full+1;
    dfs(now+1,full+1);
    for(int i = full+2;i <= n;i++)
    {
        if(f[i] != 0) continue;
        f[now] = i;
        dfs(now+1,full);
    }
    f[now] = 0;
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >>m;
    cin.get();
    s += " ";
    getline(cin,s);
    for(int i = 1;i <= n;i++) cin >> c[i];

    dfs(1,0);

    int ans = 1;
    for(int i = 1;i <= n;i++)
    {
        ans *= i;
        ans %= 998244353;
    }
    cout << ans;
    return 0;
}
//bye...
