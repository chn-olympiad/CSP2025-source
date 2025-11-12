#include <bits/stdc++.h>
using namespace std;

long long p=998244353;
int n;
int dis[5005];
long long a[5005],ans[5005];
long long cnt=0;

void dfs(int step)
{
    if(step>n)
    {
        long long sum=0;
        long long maxn=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==1)
            {
                sum+=ans[i];
                maxn=max(maxn,ans[i]);
            }
        }
        long long l=maxn*2;
        if(l<sum)
        {
            cnt++;
        }
        return;
    }
    else
    {
        dis[step]=1;
        ans[step]=a[step];
        dfs(step+1);
        dis[step]=0;
        dis[step]=0;
        ans[step]=0;
        dfs(step+1);
        dis[step]=0;
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<cnt/2%p<<endl;

    return 0;
}
