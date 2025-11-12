#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n;
int a[5010];
bool f[5010];
long long ans=0,on=0;

void dfs(int x)
{
    on++;
    if(f[x])
    {
        if(x<=n) f[x]=0;
        return;
    }
    f[x]=1;
    int cnt=0,maxn=-1,sum=0;
    for(int i=1;i<=n;i++)
        if(f[i])
            cnt++,sum+=a[i],maxn=max(maxn,a[i]);
    if(cnt>=3&&sum>maxn*2)
        ans++;
    ans%=MOD;
    for(int i=1;i<=n-x;i++) dfs(x+i);
    if(x<=n) f[x]=0;
    return;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[n+i]=1;
    }
    dfs(0);
    cout<<ans;
    return 0;
}
