#include<bits/stdc++.h>
using namespace std;

int ans,a[5010],n;
const int mod=998244353;
void dfs(int pos,int cnt,int sum,int maxs)
{
    if(pos==n+1)
    {
        if(cnt>=3&&sum>maxs*2)
            ans=ans+1%mod;
        return ;
    }
    dfs(pos,cnt+1,sum+a[pos],max(maxs,a[pos]));
    dfs(pos,cnt,sum,maxs);
}
int main()
{
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
