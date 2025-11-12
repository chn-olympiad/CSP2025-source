#include<bits/stdc++.h>
using namespace std;
int n,ans=0,a[5010];
void dfs(int depth,int sum,int num,int maxn)
{
    if(depth>=3&&sum>maxn*2)
    {
        ans++;
        ans%=998244353;
    }
    if(num>n)
    {
        return;
    }
    for(int i=num;i<=n;i++)
    {
        dfs(depth+1,sum+a[i],i+1,max(maxn,a[i]));
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0,0,1,0);
    cout<<ans;
    return 0;
}
