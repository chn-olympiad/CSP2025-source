#include<bits/stdc++.h>
using namespace std;
struct G
{
    int a,b,c;
}g[100005];
int n,t;
long long dfs(int x,int a,int b,int c)
{
    long long maxx = -1;
    if (a < n / 2)
        maxx = maxx > g[x].a ? maxx : g[x].a;
    if (b < n / 2)
        maxx = maxx > g[x].b ? maxx : g[x].b;
    if (c < n / 2)
        maxx = maxx > g[x].c ? maxx : g[x].c;
    if (x == n)
    {
        return maxx;
    }
    int sd;
    long long maxx2 = -1;
    if (a < n / 2)
    {
        sd = dfs(x + 1,a + 1,b,c) + g[x].a;
        maxx2 = maxx2 > sd ? maxx2 : sd;
    }
    if (b < n / 2)
    {
        sd = dfs(x + 1,a,b + 1,c) + g[x].b;
        maxx2 = maxx2 > sd ? maxx2 : sd;
    }
    if (c < n / 2)
    {
        sd = dfs(x + 1,a,b,c + 1) + g[x].c;
        maxx2 = maxx2 > sd ? maxx2 : sd;
    }
    return maxx2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for (int asdf = 1;asdf <= t;asdf++)
    {
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> g[i].a >> g[i].b >> g[i].c;
        cout << dfs(1,0,0,0) << endl;
    }
    return 0;
}
