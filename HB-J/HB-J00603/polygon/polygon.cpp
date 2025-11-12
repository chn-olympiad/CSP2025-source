#include <bits/stdc++.h>
using namespace std;

int n,a[5005],f[5005],p=0;
long long ans=0;
const long long mod=998244353;

void dfs (int t)
{
    if (t>n)
    {
        int s=0,k=0,m=0;
        for (int i=1;i<=n;i++)
        {
            k=k+f[i];
            s=s+f[i]*a[i];
            m=max(m,a[i]*f[i]);
        }
        if (k>=3&&s>2*m)
        {
            //cout<<k<<" "<<s<<" "<<m<<endl;
            ans=(ans+1)%mod;
            return ;
        }
    }
    else
    {
        f[t]=1;
        dfs (t+1);
        f[t]=0;
        dfs (t+1);
        return ;
    }
}

int main ()
{
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        p=p+a[i];
    }
    //sort (a+1,a+n+1);
    if (p==n)
    {
        ans=1;
        for (int i=1;i<=n;i++)
        {
            ans=(ans*2)%mod;
        }
        ans=(ans-1-n-n*(n-1)/2+mod)%mod;
        cout<<ans;
        return 0;
    }
    dfs (1);
    cout<<ans;
    return 0;
}
