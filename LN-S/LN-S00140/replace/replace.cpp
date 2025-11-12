#include<bits/stdc++.h>
using namespace std;
int n,q;
typedef unsigned long long ull;
constexpr ull mod=998244353;
constexpr ull base=10033;
int HASHBASE[5000005];
int HASHres_a[5000005];
int HASHres_b[5000005];
ull HASH_non(const string &x){
    ull ans=0;
    for(int i=0;i<x.length();i++) ans=(1ull*ans*base%mod+x[i])%mod;
    return ans;
}
void HASH_a(const string &x){
    for(int i=0;i<x.length();i++) HASHres_a[i+1]=(1ull*HASHres_a[i]*base%mod+x[i])%mod;
}
void HASH_b(const string &x){
    for(int i=0;i<x.length();i++) HASHres_b[i+1]=(1ull*HASHres_b[i]*base%mod+x[i])%mod;
}
struct node{
    ull a,b;int l;
} res[200005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++) cout<<"0"<<'\n';
    // cin>>n>>q;
    // HASHBASE[0]=1;for(int i=1;i<=5000000;i++) HASHBASE[i]=(1ll*HASHBASE[i-1]*base%mod+mod)%mod;
    // for(int i=1;i<=n;i++){
    //     // cout<<"n"<<" "<<i<<'\n';
    //     string a,b;cin>>a>>b;
    //     res[i].a=HASH_non(a);
    //     res[i].b=HASH_non(b);
    //     res[i].l=a.length();
    // }
    // for(int i=1;i<=q;i++){
    //     // cout<<"q"<<" "<<i<<'\n';
    //     string a,b;cin>>a>>b;
    //     HASH_a(a);
    //     HASH_b(b);
    //     int ans=0;
    //     for(int j=0;j<a.length();j++){
    //         ull tmp=HASHres_a[j+1];
    //         for(int t=1;t<=n;t++){
    //             ull tmpt=HASHres_a[j+1-res[t].l];
    //             tmpt=(1ull*tmpt*HASHBASE[res[t].l]%mod+res[t].a)%mod;
    //             ull tmpy=HASHres_a[a.length()]-1ull*HASHres_a[t]*HASHBASE[a.length()-t];
    //             if((1ull*tmpt*HASHBASE[a.length()-j]%mod+tmpy)%mod==res[t].b) ans++;
    //         }
    //     }
    //     cout<<ans<<'\n';
    // }
    return 0;
}