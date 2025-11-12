#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[5025];

long long ans;
void dfs(long long x,long long maxx,long long si,long long sii)
{
    if(maxx*2<x && si>=3)
    {
        ans++;
    }
    if(sii==n)
    {
        return;
    }
    for(int i=0;i<=1;i++)
    {
        dfs(x+i*a[sii+1],max(maxx,i*a[sii+1]),si+i,sii+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    //
    if(n==3)
    {
        long long x=max(a[1],a[2]);
        x=max(x,a[3]);
        if(x*2<a[1]+a[2]+a[3])
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
        return 0;
    }
    //

    dfs(0,0,0,0);

    ans=ans%998244353;
    cout<<ans<<endl;

    return 0;
}
