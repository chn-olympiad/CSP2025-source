#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],ans,n,k;
void dfs(int l,int sum)
{
    for(int len=1;len<=n-l+1;len++)
    {
        for(int i=l;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(i==j)
            {
                if(a[i]==k)
                    dfs(j+1,sum+1);
                continue;
            }
            int now=a[i];
            for(int k=i+1;k<=j;k++)
                now=now^a[k];
            if(now==k)
                dfs(j+1,sum+1);

        }
    }
    ans=max(ans,sum);
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                ans++;
            else if(a[i+1]==a[i])
            {

                ans++;
                i++;
            }
        }
        printf("%lld",ans);
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i])
                ans++;
            else if(a[i+1]!=a[i])
            {
                ans++;
                i++;
            }
        }
        printf("%lld",ans);
        return 0;
    }
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
