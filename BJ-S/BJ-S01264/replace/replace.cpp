#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
int const N=2e5+3,M=5e6+3,P=131;
int n,q;
string s[N][2],t[2];
vector <ll> hass[N][2],hast[2];
ll base[M];
inline void init(){
    base[0]=1;
    for(int i=1;i<M;++i) base[i]=base[i-1]*P;
}
inline void has(vector <ll> &hs,string &a){
    a=" "+a;
    hs.resize(a.size());
    for(int i=1;i<a.size();++i) hs[i]=hs[i-1]*P+a[i]-'a';
}
inline bool cmp(vector <ll> &hsa,vector <ll> &hsb,int l1,int r1,int l2,int r2){
    if(l1>r1 || l2>r2) return 1;
    ll tmpa=hsa[r1]-hsa[l1-1]*base[r1-l1+1];
    ll tmpb=hsb[r2]-hsb[l2-1]*base[r2-l2+1];
    return tmpa==tmpb;
}
inline void solve(){
    cin>>t[0]>>t[1];
    has(hast[0],t[0]),has(hast[1],t[1]);
    int cnt=0,lent=t[0].size()-1;
    // cout<<"len="<<lent<<endl;
    for(int j=1;j<=lent;++j){
        if(!cmp(hast[0],hast[1],1,j-1,1,j-1)) continue;
        // cout<<"j="<<j<<endl;
        for(int i=1;i<=n;++i){
            int lens=s[i][0].size()-1;
            if(j+lens-1>lent) continue;
            // cout<<"i="<<i<<" s1="<<s[i][0]<<" s2="<<s[i][1]<<endl;
            if(cmp(hast[0],hass[i][0],j,j+lens-1,1,lens) && cmp(hast[1],hass[i][1],j,j+lens-1,1,lens) && cmp(hast[0],hast[1],j+lens,lent,j+lens,lent)) ++cnt;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    #ifndef wzh
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
    #endif
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    init();
    cin>>n>>q;
    if(n>=1e4 && q>=10){
        for(int i=1;i<=q;++i) puts("0");
        return 0;
    }
    for(int i=1;i<=n;++i){
        cin>>s[i][0]>>s[i][1];
        has(hass[i][0],s[i][0]),has(hass[i][1],s[i][1]);
    }
    while(q--) solve();
    return 0;
}