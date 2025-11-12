#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N],xo[N]={0};
bool mp[N];
bool cmp(pair<ll,ll> p1,pair<ll,ll> p2){
    return p1.second-p1.first<p2.second-p2.first;
}
bool judge(pair<ll,ll> x){
    for(ll i=x.first;i<=x.second;i++){
        if(mp[i]==true) return false;
    }
    for(ll i=x.first;i<=x.second;i++){
        mp[i]=true;
    }
    return true;
}
vector<pair<ll,ll> > v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k,cnt=0;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        xo[i] = xo[i-1]^a[i];
        if(xo[i]==k) v.push_back({1,i});
    }
    for(ll i=2;i<=n;i++)
        for(ll j=i;j<=n;j++){
            if((xo[j] ^ xo[i-1])==k) v.push_back({i,j});
        }
    sort(v.begin(),v.end(),cmp);
    for(auto x:v){
        if(judge(x)) cnt++;
    }
    cout<<cnt;
    return 0;
}
