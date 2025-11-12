#include<bits/stdc++.h>
using namespace std;
// #define debug
typedef long long ll;
string s[200050][3];
ll hsh[200050][3];
ll hshx[200050],hshy[200050];
map<int,set<int>>mp;
ll p=131,mod=998244353;
ll fpow(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=2;j++){
            for(ll k=0;k<s[i][j].size();k++){
                hsh[i][j]=(hsh[i][j]*p+(s[i][j][k]-'a'+1))%mod;
            }
        }
        mp[hsh[i][1]].insert(hsh[i][2]);
    }
    while(q--){
        string x,y;
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<endl;
            continue;
        }
        ll st=0,fs=0;
        for(ll i=0;i<x.size();i++){
            hshx[i]=(hshx[i-1]*p+(x[i]-'a'+1))%mod;
            hshy[i]=(hshy[i-1]*p+(y[i]-'a'+1))%mod;
            if(x[i]!=y[i]){
                if(!st)st=i;
                fs=i;
            }
        }
        ll ans=0;
        for(ll i=1;i<=x.size();i++){
            for(ll j=max(i-1,fs);j<=st+i-1;j++){
                ll hx,hy;
                if(j==i-1){
                    hx=hshx[j];
                }else{
                    hx=hshx[j]-hshx[j-i]*fpow(p,i);
                }
                if(j==i-1){
                    hy=hshy[j];
                }else{
                    hy=hshy[j]-hshy[j-i]*fpow(p,i);
                }
                #ifdef debug
                cout<<hx<<" "<<hy<<endl;
                #endif
                if(mp[hx].count(hy)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}