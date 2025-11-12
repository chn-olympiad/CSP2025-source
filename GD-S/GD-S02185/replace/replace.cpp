#include<bits/stdc++.h>
using namespace std;
// balanced TREE?
namespace SOLVE{
#define N 200000
#define ll long long
#define ull unsigned ll
#define LEN 5000000
int n,q;
string s1[N+1],s2[N+1],t1[N+1],t2[N+1];
int slen[N+1];
int ans[N+1];
ull mkhsh(string s){
    ull res=0;
    for(int i=0;i<s.size();++i)res=res*51001+s[i];
    return res;
}
map<pair<ull,int>,int> vis;
int cnt;
int trie[LEN+1][26],tot;
int cnt[LEN+1][27];
inline int id(const char &c){return c-'0';}
inline int go(const int &x,const char &c){
    if(!trie[x][id(c)])trie[x][id(c)]=++tot;
    return trie[x][id(c)];
}
inline int un_go(const int &x,const char &c){
    return trie[x][id(c)];
}
inline void insert(ull hsh,string lt,string rt){
    int lenl=lt.size(),lenr=rt.size();
    int k=lenl-lenr;
    int hd;
    if(k>0){
        k=(k+1)/2;
        if(!vis[{hsh,k}])vis[{hsh,k}]=++cnt;
        hd=vis[{hsh,k}];
        for(int i=0;i<lenl-k;++i){
            char lc=lt[i+k],rc;
            if(i<k)rc=lt[k-1-i];
            else rc=rt[i-k];
            hd=go(hd,lc);
            hd=go(hd,rc);
        }
        if((lenl+lenr)&1){
            cnt[hd][rt[lenr-1]]++;
        }else{
            cnt[hd][26]++;
        }
    }else{
        k=abs(k);
        k=(k+1)/2;
        if(!vis[{hsh,-k}])vis[{hsh,-k}]=++cnt;
        hd=vis[{hsh,-k}];
        for(int i=0;i<lenr-k;++i){
            char rc=rt[i+k],lc;
            if(i<k)lc=rt[k-1-i];
            else lc=lt[i-k];
            hd=go(hd,lc);
            hd=go(hd,rc);
        }
        if((lenl+lenr)&1){
            cnt[hd][lt[lenl-1]]++;
        }else{
            cnt[hd][26]++;
        }
    }
}
inline int find(ull hsh,string lt,string rt){
    int lenl=lt.size(),lenr=rt.size();
    int k=lenl-lenr;
    int hd;
    int res=0;
    if(k>0){
        k=(k+1)/2;
        if(!vis[{hsh,k}])return 0;
        hd=vis[{hsh,k}];
        if()
        for(int i=0;i<lenl-k;++i){
            char lc=lt[i+k],rc;
            if(i<k)rc=lt[k-1-i];
            else rc=rt[i-k];
            hd=un_go(hd,lc);
            if(!hd)return res;
            hd=un_go(hd,rc);
            if(!hd)return res;
        }
        if((lenl+lenr)&1){
            cnt[hd][rt[lenr-1]]++;
        }else{
            cnt[hd][26]++;
        }
    }else{
        k=abs(k);
        k=(k+1)/2;
        if(!vis[{hsh,-k}])return 0;
        hd=vis[{hsh,-k}];
        for(int i=0;i<lenr-k;++i){
            char rc=rt[i+k],lc;
            if(i<k)lc=rt[k-1-i];
            else lc=lt[i-k];
            hd=un_go(hd,lc);
            if(!hd)return res;
            hd=un_go(hd,rc);
            if(!hd)return res;
        }
        if((lenl+lenr)&1){
            cnt[hd][lt[lenl-1]]++;
        }else{
            cnt[hd][26]++;
        }
    }
}
inline void solve(){
    for(int i=1;i<=n;++i){
        slen[i]=s1[i].size();
        int l=0,r=slen[i];
        while(l<r&&s1[i][l]==s2[i][l])++l;
        if(l==r)continue;
        while(l<r&&s2[i][r-1]==s1[i][r-1])--r;
        ull hs1=mkhsh(s1[i].substr(l,r));
        ull hs2=mkhsh(s2[i].substr(l,r));
        insert((hs1^hs2),s1[i].substr(0,l),s1[i].substr(r,slen[i]));
    }
    for(int i=1;i<=q;++i){
        if(t1[i].size()!=t2[i].size())continue;
        int len=t1[i].size();
        int l=0,r=len;
        while(l<r&&t1[i][l]==t2[i][l])++l;
        if(l==r)continue;
        while(l<r&&t2[i][r-1]==t1[i][r-1])--r;
        ull hs1=mkhsh(t1[i].substr(l,r));
        ull hs2=mkhsh(t2[i].substr(l,r));
        ans[i]=find((hs1^hs2),t1[i].substr(0,l),t1[i].substr(r,len));
    }
}
inline void solve_q1(){
    ull midhs,lhs,rhs;
    int L,R;
    prepare:{
        int len=t1[1].size();
        if(t1[1].size()!=t2[i].size())return;
        int l=0,r=len;
        while(l<r&&t1[1][l]==t2[1][l])++l;
        while(l<r&&t1[1][r-1]==t2[1][r-1])--r;
        midhs=mkhsh(t1[1].substr(l,r));
        midhs^=mkhsh(t2[1].substr(l,r));
        lhs=mkhsh(t1[1].substr(0,l));
        rhs=mkhsh(t1[1].substr(r,len));
        L=l,R=r;
    }
    for(int i=1;i<=n;++i){
        slen[i]=s1[i].size();
        int l=0,r=slen[i];
        while(l<r&&s1[i][l]==s2[i][l])++l;
        if(l==r)continue;
        while(l<r&&s2[i][r-1]==s1[i][r-1])--r;
        ull hs1=mkhsh(s1[i].substr(l,r));
        ull hs2=mkhsh(s2[i].substr(l,r));
        ull mhs=(hs1^hs2);
        if(mhs==midhs){
            int flag=1;
            if(L<l){
                flag=0;
                continue;
            }
            for(int j=0;j<l;++j){
                if(s1[i][l-j+1]!=t1[1][L-j+1])flag=0;
            }
            for(int j=0;j<len-r;++j){
                if(j+R>=len){
                    flag=0;
                    break;
                }
                if(s1[i][j+r]!=t1[1][j+R])flag=0;
            }
            if(flag)++ans[1];
        }
    }
}
void main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0)->ios::sync_with_stdio(false);
    cin>>n>>q;
    int L1=0,L2=0;
    for(int i=1;i<=n;++i)cin>>s1[i]>>s2[i],L1+=s1[i].size()+s2[i].size();
    for(int i=1;i<=q;++i)cin>>t1[i]>>t2[i],L2+=t1[i].size()+t2[i].size();
    if(q==1)solve_q1();
    else solve();
    for(int i=1;i<=q;++i)cout<<ans[i]<<'\n';
}
}
int main(){SOLVE::main();return 0;}