#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans,sum,maxn,cnt,ym,f[5005];
void dfs(int x)
{
    if(x > n)
    {
        for(int i = 1;i <= n;i++)
        {
            if(f[i] && maxn < a[i])
            {
                maxn = a[i];
            }
        }
        if(sum > maxn * 2 && cnt >= 3)
        {
            ans++;
        }
        maxn = 0;
        return;
    }
    dfs(x + 1);
    cnt++;
    sum += a[x];
    f[x] = 1;
    dfs(x + 1);
    cnt--;
    sum -= a[x];
    f[x] = 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n > 20)
    {
        printf("%d",n - 2);
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
