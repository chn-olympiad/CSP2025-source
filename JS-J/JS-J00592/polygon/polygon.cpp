#include<bits/stdc++.h>
using namespace std;
long long n,a[5011],ans=0;
void dfs(int xunhuan,int zuihou,int flag,int b)
{
    if(xunhuan==0)
    {
        if((zuihou*2)<flag)
        {
            ans=(ans+1)%998244353;
        }
        return;
    }
    for(int i=b+1;i<=n-xunhuan+1;i++)
    {
        dfs(xunhuan-1,a[i],flag+a[i],i);
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
        if(a[i]==0)
        {
            i--;
            n--;
        }
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        dfs(i,0,0,0);
    }
    cout<<ans;
    return 0;
}
