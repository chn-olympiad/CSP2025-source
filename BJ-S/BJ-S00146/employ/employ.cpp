#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
string s;
int a[10005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;++i)cin>>a[i];
    ll ans=1;
    for(int i=1;i<=n;++i)ans=ans*i%mod;
    cout<<ans<<endl;
    return 0;
}