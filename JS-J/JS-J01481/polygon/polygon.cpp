#include<bits/stdc++.h>
using namespace std;
int a[10005],h[10005];
int gs=0;
int n;
void dg(int dep,int tot,int mx,int js)
{
    if(dep>n)
    {
        if(tot>2*mx&&js>=3)
        {
            gs++;
        }
        return;
    }
    dg(dep+1,tot+a[dep],max(mx,a[dep]),js+1);
    dg(dep+1,tot,mx,js);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            f=0;
        }
    }
    if(f==0)
    {
        dg(1,0,0,0);
        cout<<gs;
        return 0;
    }
    unsigned long long tot=0;
    long double cf1=1;
    for(int i=n;i>=4;i--)
    {
        cf1=(unsigned long long)(cf1*1.0/(n-i+1)*i)%998244353;
        tot=(tot+(unsigned long long)(cf1))%998244353;
    }
    cout<<tot+1;
    return 0;
}
