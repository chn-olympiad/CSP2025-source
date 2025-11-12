#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510];
int x[510];
bool vis[510];
int ans = 0;
void check()
{
    int ded = 0;
    for(int i = 1;i <= n;i++)
    {
        if(ded >= a[x[i]])
        {
            ded++;
            continue;
        }
        if(s[i] == '0')
            ded++;
    }
    if(n - ded >= m)
        ans++;
}
void dfs(int pos)
{
    if(pos == n +1)
    {
        check();
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])
            continue;
        vis[i] = 1;
        x[pos] = i;
        dfs(pos +1);
        vis[i] = 0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    s = '%' +s;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    dfs(1);
    cout << ans;
}
