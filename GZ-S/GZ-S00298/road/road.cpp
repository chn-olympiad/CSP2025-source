// GZ-S00298 遵义四中 温岳城

#include<bits/stdc++.h>
using namespace std;
// 0 pts, 没复习图论导致老实了这一块/.
#define ll long long
int main()
{
    freopen("road.in","r",stdin);freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> a(m),b(m),c(m);for(ll i=0;i<m;i++) cin>>a[i]>>b[i]>>c[i];
    sort(c.begin(),c.end());
    ll sum=0;
    for(int i=0;i<n-1;i++) sum+=c[i];
    cout<<sum;
}
