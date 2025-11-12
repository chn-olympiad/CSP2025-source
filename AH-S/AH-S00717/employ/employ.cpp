#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500+10,INF=998244353;
ll n,m,a[N],cnt;
string s;
ll ak(ll x){
    ll ans=1;
    for(ll i=1;i<=x;i++) ans=(ans*i)%INF;
    return ans;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(s[i-1]=='1') cnt++;
    }
    if(cnt<m){
        cout<<0;
        return 0;
    }
    ll ans1=1;
    for(ll i=n;i>=n-m=1;i--) ans=(ans*i)%INF;
    for(ll i=1;i<=m;i++) ans/=i;
    cout<<ans;
    return 0;
}
