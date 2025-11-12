#include <bits/stdc++.h>
using namespace std;

int n;
int a[6000];
long long int ans;
void dfs(int Maxn,int sum,int st)
{
    if(Maxn * 2 < sum && st >= 3)
    {
        ans++;
        ans %= 998244353;
    }
    if(st == n)
    {
        return;
    }
    for(int i = st + 1;i <= n;i++)
    {
        dfs(max(Maxn,a[i]),sum + a[i],i);
    }

}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        dfs(a[i],a[i],i);
    }

    cout << ans;
    return 0;
}
