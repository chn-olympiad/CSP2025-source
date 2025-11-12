#include <bits/stdc++.h>
using namespace std;
int n,a[5100];
long long ans,c[5010];
int dfs(int x,int y,int z)
{
    long long h=0;
    if(x==1)
    {
        for(int i=y;i<=n;i++)
        {
            if(a[i]<z)h++;
        }
        return h;
    }
    for(int i=y;i<=n-x+1;i++)
    {
        h+=dfs(x-1,i+1,z+a[i]);
    }
    return h;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=20)
    {
        for(int i=3;i<=n;i++)
        {
            ans+=dfs(i,1,0);
        }
        cout<<ans;
        return 0;
    }
    c[2]=2;
    for(int i=3;i<=n;i++)
    {
        c[i]=c[i-1]*i;
    }
    for(int i=3;i<=n;i++)
    {
        ans+=c[n]/c[i];
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
