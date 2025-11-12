#include<bits/stdc++.h>
#define CSP2025 using
#define RP namespace
#define plusplus std
CSP2025 RP plusplus;
inline int rd(){int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);return x*f;}
constexpr int N=2e5+5;
string s1[N],s2[N];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>s1[i]>>s2[i];
    while(q--){
        string t1,t2;int l1,l2,ans=0;
        cin>>t1>>t2;l1=t1.size(),l2=t2.size();
        for(int i=1;i<=n;++i){
            int l=s1[i].size();
            for(int j=0;j<=l1-l;++j){
                string t0=t1;
                t0.replace(j,l,s2[i]);
                if(t1.substr(j,l)==s1[i]&&t0==t2)++ans;
            }
        }cout<<ans<<'\n';
    }
}
/*
6 1
a b
xax xbx
xxa xxb
xaxx xbxx
xxxxa xxxxb
axxx bxxx
xxaxx xxbxx
*/
