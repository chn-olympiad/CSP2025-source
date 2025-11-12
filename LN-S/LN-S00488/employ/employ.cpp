#include <bits/stdc++.h>

using namespace std;

int dis[20] , vis[20] , a[510];
string s;
int n , m;
long long ans;
const int mod = 998244353;

void work()
{
    int sum1 = 0 , sum2 = 0;
    for(int i = 1; i <= n; ++ i)
    {
        if(s[i - 1] == '0') sum2 ++;
        else if(sum2 >= a[dis[i]]) sum2 ++;
        else sum1 ++;
    }
    if(sum1 >= m) ans ++;
}

void dfs(int x)
{
    if(x == n + 1)
    {
        work();
        return;
    }
    for(int i = 1; i <= n; ++ i)
    {
        if(vis[i]) continue;
        vis[i] = 1;
        dis[x] = i;
        dfs(x + 1);
        vis[i] = 0;
    }
}

int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    if(n <= 10)
    {
        dfs(1);
        cout << ans;
        return 0;
    }
    if(m == n)
    {
        for(int i = 1; i <= n; ++ i)
        {
            if(a[i] == 0)
            {
                return 0;
            }
        }
        for(int i = 0; i < s.size(); ++ i)
        {
            if(s[i] == '0')
            {
                cout << 0;
                return 0;
            }
        }
        long long sum = 1;
        for(int i = 1; i <= n; ++ i) sum *= i , sum %= mod;
        cout << sum;
    }
    return 0;
}