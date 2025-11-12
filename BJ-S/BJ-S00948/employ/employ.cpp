#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n, m, c[1000005], k;
int f[1005];
string s;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i+1];
        if(s[i]!=1) k=1;
    }
    if(!k)
    {
        f[1]=1;
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]*i%mod;
        }
        if(f[n]<f[m]) cout<<f[n]*mod/f[m];
        cout<<f[n]/f[m];
    }
    if(m==n)
    {
        if(k) cout<<0;
        else{
            f[1]=1;
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]*i%mod;
        }
        if(f[n]<f[m]) cout<<f[n]*mod/f[m];
        cout<<f[n]/f[m];
        }
    }
    return 0;
}
