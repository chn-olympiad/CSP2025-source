#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,B=1331,P=1e9+7;
ll n,q,h[N][2],p[N];
map<pair<ll,ll>,ll> mp;
string s1,s2,t1,t2;
ll cal(ll l,ll r,ll t){
    return (h[r][t]-h[l-1][t]*p[r-l+1]%P+P)%P;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>s1>>s2;ll res=0,res2=0;
        for(ll j=0;j<s1.size();j++) res=(res*B+s1[j])%P,res2=(res2*B+s2[j])%P;
        mp[{res,res2}]++;
    }
    p[0]=1;
    for(ll i=1;i<=n;i++) p[i]=p[i-1]*B%P;
    while(q--){
        cin>>t1>>t2;ll m=t1.size();t1=" "+t1;t2=" "+t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";continue;
        }
        ll p=0;
        for(ll i=1;i<=m;i++){
            if(t1[i]!=t2[i]) p=i;
            h[i][0]=(h[i-1][0]*B+t1[i])%P;
            h[i][1]=(h[i-1][1]*B+t2[i])%P;
        }
        ll ans=0;
        for(ll i=1;i<=m;i++){
            for(ll j=max(i,p);j<=m;j++){
                ll res=cal(i,j,0),res2=cal(i,j,1);
                if(mp.count({res,res2})) ans+=mp[{res,res2}];
            }
            if(t1[i]!=t2[i]) break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
