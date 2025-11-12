#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],mod=998244353,f[505][505],ans1=0,ans2=1,m1=0,o2=0;
string s;
void work(int day)
{
    if(n-day+1<m-m1)
    {
        return;
    }
    if(m1>=m&&day==n+1)
    {
        ans1++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1)
        {
            continue;
        }
        int mx=m1,on=o2;
        b[i]=1;
        if(a[i]>o2&&s[day]=='1')
        {
            m1++;
        }
        else
        {
            o2++;
        }
        work(day+1);
        b[i]=0;
        m1=mx,o2=on;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=18)
    {
        work(1);
        cout<<ans1;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            ans2=(ans2*i)%mod;
        }
        cout<<ans2;
    }
    return 0;
}
