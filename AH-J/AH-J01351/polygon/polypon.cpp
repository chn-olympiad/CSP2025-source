#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5003],sum,n,maxn,s[5003];
void try12()
{
    if(n<3)
    {
        cout<<0;
        return ;
    }
    if(sum>2*maxn)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
void try32()
{
    ll sum2=0;
    for(ll i=1;i<=n;i++)
    {
        s[i]=s[i-1]+i;
    }
    for(int i=1;i<=n-2;i++)
    {
        sum2=sum2+s[i];
    }
    cout<<sum2;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<=3)
    {
        try12();
        return 0;
    }
    if(maxn<=1)
    {
        try32();
        return 0;
    }
}
