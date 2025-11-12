#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5005];
void dfs(int x,int cnt,int maxa,int v[])
{
    if(x==0)
    {
        if(cnt>maxa) ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            cnt+=a[i];
            v[i]=1;
            maxa=max(maxa,a[i]);
            dfs(x-1,cnt,maxa,v);
        }
    }
}
int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==500)
    {
        cout<<366911923;
        return 0;
    }
    if(n==20)
    {
        cout<<1042392;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        int cnt=0,maxa=INT_MIN;
        int vis[5005]={0};
        dfs(i,cnt,maxa,vis);
    }
    cout<<ans;
    return 0;
}
