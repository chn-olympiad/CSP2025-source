#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int mo=998244353;
int n;
int a[N];
long long f[N];
long long ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    f[1]=1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) f[i]=f[i-1]*i%mo;
    for(int i=3;i<=n;i++)
    {
        ans+=f[n]/f[i];
        ans%=mo;
    }
    cout<<ans<<endl;
    return 0;
}