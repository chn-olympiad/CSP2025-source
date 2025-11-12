#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,base1=541,mod1=998244353,base2=436,mod2=1e9+7;
int n,q,st,ed;
struct node{
    ll ha,hb,ya,yb;
    bool operator<(const node& yxt)const{
        if(ha!=yxt.ha) return ha<yxt.ha;
        if(hb!=yxt.hb) return hb<yxt.hb;
        if(ya!=yxt.ya) return ya<yxt.ya;
        return yb<yxt.yb;
    }
};
map<node,bool> mp;
string a,b;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        ll x=0,y=0,w=0,z=0;
        for(int j=0;j<a.size();j++){
            x=(x*base1+a[j])%mod1;
            y=(y*base2+a[j])%mod2;
        }
        for(int j=0;j<b.size();j++){
            w=(w*base1+b[j])%mod1;
            z=(z*base2+b[j])%mod2;
        }
        mp[{x,y,w,z}]=1;
    }
    while(q--){
        ll ans=0;
        cin>>a>>b;st=0,ed=a.size()-1;
        if(a.size()!=b.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<a.size();i++){
            st=i;
            if(a[i]!=b[i])
                break;
        }for(int i=a.size()-1;i>=0;i--){
            ed=i;
            if(a[i]!=b[i])
                break;
        }
        for(int i=0;i<=st;i++){
            ll x=0,y=0,w=0,z=0;
            for(int j=i;j<a.size();j++){
                x=(x*base1+a[j])%mod1;
                y=(y*base2+a[j])%mod2;
                w=(w*base1+b[j])%mod1;
                z=(z*base2+b[j])%mod2;
                if(j>=ed){
                    if(mp[{x,y,w,z}]) ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
