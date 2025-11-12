#include<bits/stdc++.h>
using namespace std;
int n,a[5005],now,path[5005];
unsigned long long ans=0;
void dfs(int depth,int sum,int last)
{
    if(depth>now)
    {
        if(sum>2*path[now])
        {
            ans++;
            ans=ans%998244353;
        }
        return;
    }
    for(int i=last+1;i<=n;i++)
    {
        path[depth]=a[i];
        dfs(depth+1,sum+a[i],i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag=0;
        }
    }
    sort(a+1,a+1+n);
    for(now=3;now<=n;now++)
    {
        dfs(1,0,0);
    }
    cout<<ans;
    return 0;
}
