#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans,sum[5005];
void dfs(int p,int s)
{
    if(p>3)
    {
        if(sum[p-1]>2*(sum[p-1]-sum[p-2]))
        {
            ans++;
            ans%=998244353;
        }
        if(p<n)
        {
            for(int i = s;i <= n;i++)
            {
                sum[p] = sum[p-1]+a[i];
                dfs(p+1,i+1);
            }
        }
        else if(p==n)
        {
            for(int i = s;i <= n;i++)
            {
                sum[p] = sum[p-1]+a[i];
                if(sum[p]>2*(sum[p]-sum[p-1]))
                {
                    ans++;
                    ans%=998244353;
                }
            }
        }
        return;
    }
    for(int i = s;i <= n;i++)
    {
        sum[p] = sum[p-1]+a[i];
        dfs(p+1,i+1);
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
    sort(a+1,a+n+1);
    dfs(1,1);
    cout << ans;
    return 0;
}
