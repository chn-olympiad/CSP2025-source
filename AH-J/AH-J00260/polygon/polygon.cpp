#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 5e3 + 5;
const LL MOD = 998244353;
LL a[N], sum[N], n, maxn, ans;
void DFS(LL i, LL sum)
{
    if(sum > 2 * maxn)
    {
        ans ++;
        return;
    }
    if(i > n)
    {
        return;
    }
    DFS(i+1, sum+a[i]);
    DFS(i+1, sum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(LL i=1; i<=n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    for(LL i=1; i<=n; i++)
    {
        DFS(i, 0);
    }
    printf("%lld",ans);
    return 0;
}
