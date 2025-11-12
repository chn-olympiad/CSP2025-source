#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=5e6+56,BASE=233,MOD=998244353;
ll n,q,m,k,l,r,ans;
ll ha[2],pows[MAXN],hat[2][MAXN];
map<pair<ll,ll>,ll> mp;
string t[2],s[2];
inline ll gethat(const ll &x,const ll &l,const ll &r){
    if(l>r) return 0;
    return (hat[x][r]-hat[x][l-1]*pows[r-l+1]%MOD+MOD)%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    pows[0]=1;
    for(ll i=1;i<MAXN;i++) pows[i]=BASE*pows[i-1]%MOD;
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>s[0]>>s[1];
        m=s[0].size();
        s[0]=' '+s[0],s[1]=' '+s[1];
        ha[0]=ha[1]=0;
        for(ll j=1;j<=m;j++) ha[0]=(ha[0]*BASE+s[0][j])%MOD;
        for(ll j=1;j<=m;j++) ha[1]=(ha[1]*BASE+s[1][j])%MOD;
        mp[make_pair(ha[0],ha[1])]++;
    }
    while(q--){
        ans=0;
        cin>>t[0]>>t[1];
        k=t[0].size();
        t[0]=' '+t[0],t[1]=' '+t[1];
        for(ll i=1;i<=k;i++) hat[0][i]=(hat[0][i-1]*BASE+t[0][i])%MOD;
        for(ll i=1;i<=k;i++) hat[1][i]=(hat[1][i-1]*BASE+t[1][i])%MOD;
        for(ll i=1;i<=k;i++){
            if(gethat(0,1,i)^gethat(1,1,i)){
                l=i;
                break;
            }
        }
        for(ll i=k;i;i--){
            if(gethat(0,i,k)^gethat(1,i,k)){
                r=i;
                break;
            }
        }
        for(ll i=1;i<=l;i++) for(ll j=r;j<=k;j++) if(mp.count(make_pair(gethat(0,i,j),gethat(1,i,j)))) ans+=mp[make_pair(gethat(0,i,j),gethat(1,i,j))];
        cout<<ans<<'\n';
    }
    return 0;
}
