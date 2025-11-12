#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
long long f[505];
string s;
void in()
{
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=(f[i-1]*i)%mod;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<((f[n]+mod)/f[n-m]/f[m])%mod;
    return 0;
}
