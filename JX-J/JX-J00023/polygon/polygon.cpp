#include<bits/stdc++.h>
using namespace std;
int n;
int arr[5005];
bool b[5005];
long long tot;
void dfs(int cur)
{
    if(cur==n+1)
    {
        long long h=0,mmax=0;
        for(int i=1;i<=n;++i)
        {
            if(b[i]) h+=arr[i],mmax=max(mmax,(long long)arr[i]);
        }
        if(mmax*2<h)
        {
            ++tot;
            tot%=998244353;
        }
        return;
    }
    b[cur]=true;
    dfs(cur+1);
    b[cur]=false;
    dfs(cur+1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
    dfs(1);
    printf("%lld\n",tot);
    return 0;
}
