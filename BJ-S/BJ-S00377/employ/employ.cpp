#include<iostream>
#include<cstdio>
using namespace std;

const int mod = 998244353;
string s;

int c[10005], n, m, plan[100005], vis[100005];

bool check()
{
    int ans = 0, tot = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(s[i - 1] == '0')
            tot ++;
        else
            if(tot < c[plan[i]])
                ans ++;
            else
                tot ++;
    }
    return ans >= m;
}
int ans;
void dfs(int step)
{
    if(step > n)
    {
        if(check())
        {
            ans ++;
            ans %= mod;
        }
        return;
    }
    for(int i = 1; i <= n; i ++)
        if(!vis[i])
        {
            plan[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
        }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    cin >> s;
    for(int i = 1; i <= n; i ++)
        cin >> c[i];
    dfs(1);
    cout << ans << endl;
}
