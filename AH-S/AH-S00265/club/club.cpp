#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+6;
ll n,m;
ll a[N],b[N],c[N];
ll aa[N],bb[N],cc[N];
struct T{
    ll x,y,z,id;
}w[N];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>m;
    while(m--){
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>w[i].a>>w[i].b>>w[i].c;
            w[i].id=i;
        }
        for(ll i=1;i<=n;i++){
            ll maxx=0;
            maxx=max(w[i].a,w[i].b);
            maxx=max(maxx,w[i].c);
            if(maxx==w[i].a){
                a[i]=maxx;
                aa[i]=1;
            }
            if(maxx==w[i].b){
                b[i]=maxx;
                bb[i]=1;
            }
            if(maxx==w[i].c){
                c[i]=maxx;
                cc[i]=1;
            }
        }
    }
    return 0;
}
