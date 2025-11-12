#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005];
int cnt[5005];
vector<int> p[5005];
int n;
long long ans=0;
long long jc[5005];
long long njc[5005];
long long qpow(int n,int k)
{
    long long ans=1;
    while(k)
    {
        if(k%2==1) ans*=n;
        n*=n;
        n%=mod;
        ans%=mod;
        k/=2;
    }
    return ans;
}
int C(int n,int m)
{
    if(n==m) return 1;
    return jc[n]*njc[m]%mod*njc[n-m]%mod;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i].push_back(a[i]);
 //       if(a[i]!=1) flag=false;
    }
    sort(a+1,a+n+1);
    if(n<=2)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    if(flag)
    {
        jc[0]=1;
        for(int i=1;i<=5000;i++)
        {
            jc[i]=jc[i-1]*i%mod;
            jc[i]%=mod;
            njc[i]=qpow(jc[i],mod-2);
        }
        for(int i=3;i<=n;i++)
        {
            ans+=C(n,i);
            ans%=mod;
        }
        cout<<ans%mod;
    }
    else{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k:p[j])
            {
                p[i].push_back(k+a[i]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j : p[i])
        {
   //         cout<<j<<" ";
            if(j>a[i])
            {
 //               cout<<j<<" ";
                ans++;
            }
        }
  //       cout<<endl;
    }
    cout<<ans;
    }
}
