#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
const int N=2e5+5,M=2e6+5;
const int B1=107,P1=1e9+21;
const int B2=2017,P2=1e9+33;
int n,Q,p1[M],p2[M],inv1[M],inv2[M],ha1[M],hb1[M];
map<pii,int> mp;
pii tar;
inline int qpow(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}
inline void init(int n){
    p1[0]=1;
    for(int i=1;i<=n;i++)p1[i]=p1[i-1]*B1%P1;
    for(int i=1;i<=n;i++)inv1[i]=qpow(p1[i],P1-2,P1);
    p2[0]=1;
    for(int i=1;i<=n;i++)p2[i]=p2[i-1]*B2%P2;
    for(int i=1;i<=n;i++)inv2[i]=qpow(p2[i],P2-2,P2);
    return;
}
inline int HA1(int l,int r){
    return (ha1[r]-ha1[l-1])*inv1[l]%P1;
}
inline int HB1(int l,int r){
    return (hb1[r]-hb1[l-1])*inv1[l]%P1;
}
// inline int H2(int l,int r){

// }
inline bool chk(int l,int r){
    return HA1(l,r)==HB1(l,r);
}
inline int getL(int len){
    int l=1,r=len,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(chk(1,mid))l=mid+1,res=mid;
        else r=mid-1;
    }
    return res;
}
inline int getR(int len){
    int l=1,r=len,res=len+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(chk(mid,len))r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
inline pii work(string a,string b){
    int len1=a.length(),len2=b.length();
    a=" "+a,b=" "+b;
    for(int i=1;i<=len1;i++)ha1[i]=(ha1[i-1]+p1[i]*(int)(a[i])%P1)%P1;
    // for(int i=0;i<len1;i++)ha2[]
    for(int i=1;i<=len2;i++)hb1[i]=(hb1[i-1]+p1[i]*(int)(b[i])%P1)%P1;
    int x=getL(len1)+1,y=getR(len1)-1;
    // cerr<<x<<' '<<y<<' '<<y-x+1<<endl;
    pii res=mkp(HA1(x,y),HB1(x,y));
    if(res==tar){
        // cerr<<a<<' '<<b<<endl;
        // cerr<<"a: "<<len1<<endl;
        // for(int i=1;i<=len1;i++)cerr<<ha1[i]<<' ';
        // cerr<<endl;
        // cerr<<x<<' '<<y<<' '<<res.fi<<' '<<res.se<<endl;
    }
    for(int i=1;i<=len1;i++)ha1[i]=0;
    for(int i=1;i<=len2;i++)hb1[i]=0;
    return res;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init(M-5);

    // for(int i=1;i<=5;i++)cerr<<p1[i]<<' ';
    // cerr<<endl;
    // for(int i=1;i<=5;i++)cerr<<inv1[i]<<' ';
    // cerr<<endl;

    tar=work("m","d");

    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        if(s1.length()!=s2.length())continue;
        pii res=work(s1,s2);
        // if(res==tar)cerr<<"-----------"<<endl;
        mp[res]++;
    }
    while(Q--){
        string t1,t2;cin>>t1>>t2;
        // cerr<<t1<<' '<<t2<<endl;
        if(t1.length()!=t2.length()){cout<<0<<'\n';continue;}
        cout<<mp[work(t1,t2)]<<'\n';
    }
    return 0;
}