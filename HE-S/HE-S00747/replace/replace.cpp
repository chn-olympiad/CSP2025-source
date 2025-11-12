#include<bits/stdc++.h>
using namespace std;
using llt=long long;
using ull=unsigned long long;
const ull B=13331;
const llt N=5100000,D=27;
llt n,q,aS[N],aT[N],qS[N],qT[N],ans[N];char in[2][N];
map<ull,llt> mp;
struct BIT
{
    llt B[N];
    void add(llt x,llt v){for(int i=x;i<N;i+=(i&(-i))) B[i]+=v;}
    llt sum(llt x){llt res=0;for(int i=x;i;i-=(i&(-i))) res+=B[i];return res;}
}bit;
struct TRIE
{
    int trans[N][D],siz=0,dfn[N],sz[N],cur;vector<llt> vec[N],M[N],Q[N];
    llt ins(llt nw,char x)
    {
        llt d=x-'a';
        if(!trans[nw][d]) vec[nw].push_back(d),trans[nw][d]=++siz,nw=siz;
        else nw=trans[nw][d];
        return nw;
    }
    void dfs(llt now){dfn[now]=++cur;sz[now]=1;for(auto v:vec[now]) dfs(trans[now][v]),sz[now]+=sz[trans[now][v]];}
    void solve(llt now)
    {
        for(auto v:M[now])
            bit.add(dfn[aT[v]],1),bit.add(dfn[aT[v]]+sz[aT[v]],-1);
        for(auto v:Q[now]) ans[v]=bit.sum(dfn[qT[v]]);
        for(auto v:vec[now]) solve(trans[now][v]);
        for(auto v:M[now])
            bit.add(dfn[aT[v]],-1),bit.add(dfn[aT[v]]+sz[aT[v]],1);
    }
}trie;
ull H(llt l,llt r)
{
    ull res=0;
    for(int i=l;i<=r;i++) res=res*B+(in[0][i]-'a')*27+in[1][i]-'a';
    return res;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++) 
    {
        scanf("%s",in[0]+1);
        scanf("%s",in[1]+1);
        llt S=strlen(in[0]+1),L=0,R=S+1;
        for(int j=1;j<=S;j++) if(in[0][j]!=in[1][j]) {L=j;break;}
        for(int j=S;j>=1;j--) if(in[0][j]!=in[1][j]) {R=j;break;}
        if(L==0) continue;
        ull v=H(L,R);if(!mp.count(v)) mp[v]=++trie.siz,++trie.siz;
        llt nw=mp[v];for(int j=L-1;j>=1;j--) nw=trie.ins(nw,in[0][j]);aS[i]=nw;
        trie.M[nw].push_back(i);
        nw=mp[v]+1;for(int j=R+1;j<=S;j++) nw=trie.ins(nw,in[0][j]);aT[i]=nw;
    }


    for(int i=1;i<=q;i++) 
    {
        scanf("%s",in[0]+1);
        scanf("%s",in[1]+1);
        llt S=strlen(in[0]+1),L=0,R=S+1;
        for(int j=1;j<=S;j++) if(in[0][j]!=in[1][j]) {L=j;break;}
        for(int j=S;j>=1;j--) if(in[0][j]!=in[1][j]) {R=j;break;}
        if(L==0) continue;
        ull v=H(L,R);if(!mp.count(v)) mp[v]=++trie.siz,++trie.siz;
        llt nw=mp[v];for(int j=L-1;j>=1;j--) nw=trie.ins(nw,in[0][j]);qS[i]=nw;
        trie.Q[nw].push_back(i);
        nw=mp[v]+1;for(int j=R+1;j<=S;j++) nw=trie.ins(nw,in[0][j]);qT[i]=nw;
    }
    for(auto [u,v]:mp) trie.dfs(v),trie.dfs(v+1);
    for(auto [u,v]:mp) trie.solve(v);
    for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
    return 0;
}