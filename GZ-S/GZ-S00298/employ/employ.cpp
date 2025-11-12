// GZ-S00298 遵义四中 温岳城

#include<bits/stdc++.h>
using namespace std;
// 20 pts
#define ll long long
const ll mod=998244353;
ll fa(ll n)
{
    ll ans=1;
    for(int i=2;i<=n;i++) ans=ans*i%mod;
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    cout<<fa(n);
}
