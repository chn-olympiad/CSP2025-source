#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],k,ct;
void dfs(ll d,ll l,ll sm)
{
    if(d>k)
    {
        if(sm>a[l]*2)
        {
            ct=(ct+1)%998244353;
        }
        return;
    }
    for(int i=l+1;i<=n-k+d;i++)
    {
        dfs(d+1,i,sm+a[i]);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(k=3;k<=n;k++)
    {
        dfs(1,0,0);
    }
    cout<<ct;
    return 0;
}
