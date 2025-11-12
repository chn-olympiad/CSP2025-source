#include<bits/stdc++.h>
using namespace std;
const int maxn = 5010,mod = 998244353;
int n,ans;
int a[maxn];
void dfs(int now,int sum,int mx)
{
    if(now > n) return ;
    if(sum > mx * 2)
    {
        ans += ((n - now) + 1) % mod;
        return ;
    }
    dfs(now + 1,sum + a[now],mx);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a + 1,a + 1 + n,greater<int>());
    for(int i=1;i<n-1;i++)
    {
        dfs(i,a[i] + a[i + 1] + a[i + 2],a[i]);
    }
    printf("%d\n",ans);
    return 0;
}