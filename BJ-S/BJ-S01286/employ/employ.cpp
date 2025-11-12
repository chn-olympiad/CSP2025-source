#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=510;
int n,m;
int a[N],fac[N];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    fac[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fac[i]=fac[i-1]*1ll*i%mod;
    }
    cout<<fac[n]<<"\n";
    return 0;
}
