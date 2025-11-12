#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500009],ans,o[500009];
void dfs(long long x,long long val,long long sum)
{
    if(o[x]>sum)
        return;
    o[x]=sum;
    bool flag=0;
    int f=0;
    if(sum+n-x+1<=ans)
           return;
    for(int i=x;i<=n;++i)
    {
        val^=a[i];
        if(o[i]>sum)
        return;
        o[i]=sum;
        if(val==k)
        {
            flag=1;
            sum++;
            f=i;
            o[i]=sum;
            ans=max(ans,sum);
            break;
        }
        if(sum+n-i+1<=ans)
            return;
    }
    if(!flag)
        return;
    for(int i=f+1;i<=n;++i)
        dfs(i,0,sum);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i)//start
    {
        dfs(i,0ll,0);
    }
    printf("%lld",ans);
    return 0;
}
