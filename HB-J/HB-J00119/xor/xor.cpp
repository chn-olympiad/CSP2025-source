#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,a[500050],s[500050],cnt=1;
struct line{
    ll x,y;
};
bool cmp(line a,line b){
    return a.y<b.y;
}
vector<line> v;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    s[0]=a[0]=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i],s[i]=(s[i-1]^a[i]);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if((s[j]^s[i-1])==k) v.push_back({i,j});
        }
    }
    if(v.empty()){
        cout<<0;
        return 0;
    }
    stable_sort(v.begin(),v.end(),cmp);
    ll t=v[0].y;
    for(int i=1;i<v.size();i++){
        if(v[i].x>t) cnt++,t=v[i].y;
    }cout<<cnt;
    return 0;
}
