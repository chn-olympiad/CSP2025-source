#include<bits/stdc++.h>
using namespace std;
int a[501],ans,f[501],n,m;
string s;
long long mod=998244353;
long long jie(int n1)
{
    long long x=1;
    for(int i=2;i<=n1;i++)
        x=(x*i)%mod;
    return x;
}
void bu(int day,int tui,int lu)
{
    if(day>=n||tui>n-m) return ;
    if(lu==m)
    {
        ans=(ans+1)%mod;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(f[i]) continue;
        f[i]=1;
        if(tui>=a[i]||s[day]=='0') bu(day+1,tui+1,lu);
          else bu(day+1,tui,lu+1);
        f[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int k=1;
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(!a[i]) k=0;
    }
    if(m==n)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                k=0;
                break;}}
        if(!k) cout<<0;
          else cout<<jie(n);
        return 0;
    }
    bu(0,0,0);
    cout<<ans;
    return 0;
}

