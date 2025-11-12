#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e3 + 10;
const int mod = 998244353;
int n,a[N];
LL ans;

void dfs(int x,string zo)
{
    if(x != n + 1)
    {
        dfs(x+1,zo + '0');
        dfs(x+1,zo + '1');
        return ;
    }

    int maxs = -1;
    LL sum = 0;
    for(int i = 1;i <= n;i++)
        if(zo[i-1] == '1')
        {
            maxs = max(maxs,a[i]);
            sum += a[i];
        }
    if(maxs == -1) return ;
    if(sum > maxs * 2)
    {
        ans++;
        ans %= mod;
    }
    return ;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    dfs(1,"");
    cout << ans;
    return 0;
}
