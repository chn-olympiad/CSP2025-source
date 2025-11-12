#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10,M=6e5+10;
const LL mod=1e9+9,bs=337;
int n,q,box[M];
LL pw[M];
vector<int> H;
unordered_map<LL,int> st;
LL gethsh(string s){
    LL res=0;
    for(int i=0;i<s.size();i++) res=(res*bs+s[i])%mod;
    return res;
}
void read(){
    cin>>n>>q;
    string s1,s2;
    pw[0]=1;
    for(int i=1;i<M;i++) pw[i]=pw[i-1]*bs%mod;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        st[gethsh(s1)*mod+gethsh(s2)]++;
        box[s1.size()]++;
    }
    for(int i=1;i<M;i++) if(box[i]) H.push_back(i);
}

namespace sub1{
    LL hsh1[N],hsh2[N];
    void sol(){
        string t1,t2;
        while(q--){
            cin>>t1>>t2;
            if(t1.size()!=t2.size()){cout<<"0\n";continue;}
            int len=t1.size(),fl=len,fr=-1;
            for(int i=0;i<len;i++) if(t1[i]!=t2[i]){fl=i; break;}
            for(int i=len-1;i>=0;i--) if(t1[i]!=t2[i]){fr=i; break;}
            for(int i=0;i<len;i++) hsh1[i+1]=(hsh1[i]*bs+t1[i])%mod;
            for(int i=0;i<len;i++) hsh2[i+1]=(hsh2[i]*bs+t2[i])%mod;
            LL w1,w2;
            int ans=0,res,lim; LL pwp;
            for(int p:H) if(p>=fr-fl+1){
                res=0; pwp=pw[p]; lim=min(fl,len-p);
                for(int i=max(0,fr-p+1);i<=lim && res<box[p];i++){
                    w1=(hsh1[i+p]-hsh1[i]*pwp)%mod;
                    w2=(hsh2[i+p]-hsh2[i]*pwp)%mod;
                    if(w1<0) w1+=mod; if(w2<0) w2+=mod;
                    w1=w1*mod+w2;
                    if(st.count(w1)) res+=st[w1];
                }
                ans+=res;
            }
            cout<<ans<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    read();
    sub1::sol();
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
    return 0;
}