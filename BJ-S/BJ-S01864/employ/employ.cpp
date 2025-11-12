#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int m, a[15], c[15];
bool f[15];
bool chk()
{
    int ms = 0;
    for(int i = 1;i <= n;i++)
    {
        if((ms >= c[i]) || (s[i - 1] == '0')) ms++;
    }
    return bool(n - ms >= m);
}
int ans = 0;
void dfs(int t)
{
    if(t > n)
    {
        ans += chk();
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!f[i])
        {
            f[i] = true;
            c[t] = a[i];
            dfs(t + 1);
            f[i] = false;
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1);
    cout << ans;
    return 0;
}
