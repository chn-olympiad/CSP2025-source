#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,t1,t2,t3) for(ll i=t1;i<=t2;i+=t3)
constexpr ll N=200020,mod=1e9+73;
constexpr ll m1=10023,m2=10029;
ll n,q,a[N][2],b[N][2],p1[N][2],p2[N][2];
ll pw1[N],pw2[N];
string s[N][2];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    rep(i,1,n,1){
        cin>>s[i][0]>>s[i][1];
        for(auto j:s[i][0]){
            a[i][0]=(a[i][0]*m1+j-'a')%mod;
            b[i][0]=(b[i][0]*m2+j-'a')%mod;
        }
        for(auto j:s[i][1]){
            a[i][1]=(a[i][1]*m1+j-'a')%mod;
            b[i][1]=(b[i][1]*m2+j-'a')%mod;
        }
    }
    pw1[0]=pw2[0]=1;
    rep(i,1,N-10,1){
        pw1[i]=pw1[i-1]*m1%mod;
        pw2[i]=pw2[i-1]*m2%mod;
    }
    while(q--){
        string t1,t2;cin>>t1>>t2;
        ll len=t1.length();
        t1='!'+t1,t2='!'+t2;
        rep(i,1,len,1){
            p1[i][0]=(p1[i-1][0]*m1+t1[i]-'a')%mod;
            p1[i][1]=(p1[i-1][1]*m2+t1[i]-'a')%mod;
        }
        rep(i,1,len,1){
            p2[i][0]=(p2[i-1][0]*m1+t2[i]-'a')%mod;
            p2[i][1]=(p2[i-1][1]*m2+t2[i]-'a')%mod;
        }
        auto calc0=[&](ll l,ll r){
            if(l>r) return -1LL;
            return (p1[r][0]-p1[l-1][0]*pw1[r-l+1]%mod+mod)%mod;
        };
        auto calc1=[&](ll l,ll r){
            if(l>r) return -1LL;
            return (p2[r][0]-p2[l-1][0]*pw1[r-l+1]%mod+mod)%mod;
        };
        auto calc0_=[&](ll l,ll r){
            if(l>r) return -1LL;
            return (p1[r][1]-p1[l-1][1]*pw2[r-l+1]%mod+mod)%mod;
        };
        auto calc1_=[&](ll l,ll r){
            if(l>r) return -1LL;
            return (p2[r][1]-p2[l-1][1]*pw2[r-l+1]%mod+mod)%mod;
        };
        ll ans=0;
        rep(i,1,n,1){
            ll len2=s[i][0].length();
            rep(j,len2,len,1){
                if(calc0(j-len2+1,j)==a[i][0] && calc1(j-len2+1,j)==a[i][1]){
                    if(calc0_(j-len2+1,j)==b[i][0] && calc1_(j-len2+1,j)==b[i][1]){
                        if(calc0(1,j-len2)==calc1(1,j-len2) && calc0(j+1,n)==calc1(j+1,n)){
                            if(calc0_(1,j-len2)==calc1_(1,j-len2) && calc0_(j+1,n)==calc1_(j+1,n)) ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
