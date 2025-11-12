#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=998244353;
ll n,m;
string s;
ll c[505];
int main(){
    freopen("employ3.in","r",stdin);
    freopen("employ3.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=N;
    }
    cout<<ans;
    return 0;
}
