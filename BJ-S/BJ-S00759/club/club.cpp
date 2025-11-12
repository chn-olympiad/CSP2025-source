#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll db=1;
const ll inf=1e18;
struct node{
    ll v,c,id;
};
bool cmp(node a,node b){
    if(a.c!=b.c)return a.c>b.c;
    return a.v>b.v;
}
void solve(ll n,vector<ll>&a,vector<ll>&b,vector<ll>&c){
    vector<node>k(n+1);
    for(ll i=1;i<=n;i++){
        ll maxx=max({a[i],b[i],c[i]}),minn=min({a[i],b[i],c[i]});
        k[i]={maxx,maxx-(a[i]+b[i]+c[i]-maxx-minn),i};
    }
    sort(k.begin()+1,k.end(),cmp);
    ll ans=0;
    vector<ll>v(3);
    for(ll i=1;i<=n;i++){
        node r=k[i];
        ll id=k[i].id,f=0;
        if(a[id]==r.v)f=0;
        else if(b[id]==r.v)f=1;
        else f=2;
        if(v[f]>=n/2){
            r.v-=r.c;
            if(a[id]==r.v)v[0]++;
            else if(b[id]==r.v)v[1]++;
            else v[2]++;
            ans+=r.v;
        }
        else v[f]++,ans+=r.v;
    }
    cout<<ans<<"\n";
}
int main(){
    if(db&1)freopen("club.in","r",stdin);
    if(db&1)freopen("club.out","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>a(n+1),b(n+1),c(n+1);
        for(ll i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        solve(n,a,b,c);
    }

    return 0;
}
