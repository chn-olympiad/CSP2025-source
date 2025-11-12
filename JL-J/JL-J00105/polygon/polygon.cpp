#include<bits/stdc++.h>
int n,a[100001],dp[100001],ans=0;
using namespace std;
void dfs(int id,int m)
{
    if(m<a[id-1])
    {
        cout<<id-1<<" ";
        ans+=(id-1);
    }
    if(id == 1)
    {
        return ;
    }
    for(int i=id-1;i>=1;i--)
    {
        dfs(i,m);
        if(m>=a[i])
        {
            dfs(i,m-a[i]);
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    bool l = true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            l = false;
        }
    }
    sort(a+1,a+1+n);
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(n==3)
    {
        if(a[3]<a[1]+a[2] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])
        {
            cout<<1<<endl;
            return 0;
        }
        else
        {
            cout<<0<<endl;
            return 0;
        }
    }
    else if (l)
    {
        int m=n-2,q=0;
        for(int i=1;i<=m;i++)
        {
            q+=i;
        }
        cout<<q<<endl;
        return 0;
    }
    else
    {
        for(int i=n;i>=1;i--)
        {
            dfs(i,a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
