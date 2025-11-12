#include<bits/stdc++.h>
const int N=2e5+10;
std::string s1[N],s2[N],t1[N],t2[N];
using ll=long long;
const ll HASH=1e17+7;
std::unordered_map<ll,std::vector<std::pair<int,bool> > > vec;
ll make(std::string& s,std::string& t){
    int m=s.length(),lcp=0,lcs=m-1;
    while(lcp<m&&s[lcp]==t[lcp]) ++lcp;
    while(lcs>=0&&s[lcs]==t[lcs]) --lcs;
    ll k=0;
    for(int j=lcp;j<=lcs;j++)
        k=(k*27+s[j]-'a'+1)%HASH,
        k=(k*27+t[j]-'a'+1)%HASH;
    if(lcp!=m) s=s.substr(0,lcp),std::reverse(s.begin(),s.end());
    if(lcs!=-1) t=t.substr(lcs+1,t.length()-lcs-1);
    return k;
}
int dfn1[N],dfn2[N];
const int S=5e6+10;
struct trie{
    int tr[S][26],size;
    int next(int o,int c){
        if(!tr[o][c]) tr[o][c]=++size;
        return tr[o][c];
    }
    int dfn[N],dfncnt,siz[N];
    void dfs(int o=0){
        dfn[o]=++dfncnt;siz[o]=1;
        for(int c=0;c<26;c++) if(tr[o][c]) dfs(tr[o][c]),siz[o]+=siz[tr[o][c]];
    }
    void clear(){
        for(int i=0;i<=size;i++) memset(tr[i],0,sizeof tr[0]),dfn[i]=siz[i]=0;
        size=dfncnt=0;
    }
    int run(std::string& s){
        int o=0;
        for(int j=0;j<s.length();j++){
            if(dfncnt&&!tr[o][s[j]-'a']) return -1;
            o=next(o,s[j]-'a');
        }
        return o;
    }
}pt,st;
struct data{
    int t,x,y,op;
    bool operator<(const data& b)const{
        return t<b.t||t==b.t&&op<b.op;
    }
};
std::vector<data> opt;
namespace BIT{
    int t[S];
    int n;
    void setN(int _n){n=_n;}
    int lowbit(int x){
        return x&-x;
    }
    void add(int x,int v){
        while(x<=n){
            t[x]+=v;
            x+=lowbit(x);
        }
    }
    int ask(int x){
        int ret=0;
        while(x){
            ret+=t[x];
            x-=lowbit(x);
        }
        return ret;
    }
}
int ans[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::cin.tie(0),std::ios::sync_with_stdio(0);
    int n,q;std::cin>>n>>q;
    for(int i=1;i<=n;i++){
        std::cin>>s1[i]>>s2[i];
        ll k=make(s1[i],s2[i]);
        if(k) vec[k].emplace_back(i,0);
    }
    for(int i=1;i<=q;i++){
        std::cin>>t1[i]>>t2[i];
        if(t1[i].length()==t2[i].length())
        vec[make(t1[i],t2[i])].emplace_back(i,1);
    }
    for(auto& _:vec){
        auto& ve=_.second;
        pt.clear(),st.clear();
        for(auto p:ve){
            if(p.second){
                int i=p.first;pt.run(t1[i]),st.run(t2[i]);
            }
        }
        pt.dfs(),st.dfs();
        opt.clear();
        for(auto p:ve){
            if(!p.second){
                int i=p.first,x=pt.run(s1[i]),y=st.run(s2[i]);
                if(x!=-1&&y!=-1){
                    opt.push_back({pt.dfn[x],st.dfn[y],st.dfn[y]+st.siz[y]-1,1});
                    opt.push_back({pt.dfn[x]+pt.siz[x],st.dfn[y],st.dfn[y]+st.siz[y]-1,2});
                }
            }
        }
        for(auto p:ve){
            if(p.second){
                int i=p.first,x=pt.run(t1[i]),y=st.run(t2[i]);
                opt.push_back({pt.dfn[x],st.dfn[y],i,3});
            }
        }
        std::sort(opt.begin(),opt.end());
        BIT::setN(st.dfncnt+1);
        for(auto p:opt){
            if(p.op==1) BIT::add(p.x,1),BIT::add(p.y+1,-1);
            if(p.op==2) BIT::add(p.x,-1),BIT::add(p.y+1,1);
            if(p.op==3) ans[p.y]=BIT::ask(p.x);
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}