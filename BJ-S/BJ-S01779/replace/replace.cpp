/*
那年全国赛后，我看见 Day2T2 字符串瘫在椅子上，后面不会背了

振兴字符串荣光，我辈义不容辞

写哈希吧，不然没法在 1.5h 内获得 300 分了。

本题不弱于二维偏序（构造 a...a+b+c...c -> a...a+d+c...c），无法做到线性。

O(L1+L2+(n+q)log(n+q))

懒死了，写了个 (n+q)logL1，影响不大。

样例：abcdx。

出题人深得小汤圆学精髓。

其实我 2h 时才通过本题。

加油喵！只剩 t4 了！
*/
#include<bits/stdc++.h>
using namespace std;
namespace AfterTheRainStops{//雨停酱可爱捏，最喜欢雨停姐姐啦～
using u64=unsigned long long;
mt19937_64 rnd(20100107);
u64 _key[10000000];
char s[5000001],t[5000001];
map<u64,int>id;int _tot;
int root[200001][2];
int trie[10200001][26],tot;
vector<int>ch[10200001];
int dfn[10200001],ed[10200001],dfntot;
void dfs1(int u){
    dfn[u]=++dfntot;
    for(const auto&v:ch[u])dfs1(v);
    ed[u]=dfntot;
}
vector<int>a[10200001],b[10200001];
int p[200001],res[200001];
int c[10200001];
void add(int x,int k){
    for(;x<=dfntot;x+=(x&-x))c[x]+=k;
}
int sum(int x){
    int s=0;
    for(;x;x-=(x&-x))s+=c[x];
    return s;
}
void dfs2(int u){
    for(const auto&i:a[u])add(dfn[i],1),add(ed[i]+1,-1);
    for(const auto&i:b[u])res[i]=sum(dfn[p[i]]);
    for(const auto&v:ch[u])dfs2(v);
    for(const auto&i:a[u])add(dfn[i],-1),add(ed[i]+1,1);
}
void main(){
    for(int i=0;i<10000000;++i)_key[i]=rnd();
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf(" %s %s",s,t);
        if(strcmp(s,t)==0)continue;
        int m=strlen(s);
        int l=0;
        for(;s[l]==t[l];++l);
        int r=m-1;
        for(;s[r]==t[r];--r);
        u64 hx=0;
        for(int i=l;i<=r;++i)hx+=_key[(i-l)*2]*s[i]+_key[(i-l)*2+1]*t[i];
        int o;
        if(id.find(hx)!=id.end())o=id[hx];
        else o=id[hx]=++_tot,root[o][0]=++tot,root[o][1]=++tot;
        int cur1=root[o][0],cur2=root[o][1];
        for(int i=l;i--;){
            if(!trie[cur1][s[i]-'a'])ch[cur1].push_back(trie[cur1][s[i]-'a']=++tot);
            cur1=trie[cur1][s[i]-'a'];
        }
        for(int i=r+1;i<m;++i){
            if(!trie[cur2][s[i]-'a'])ch[cur2].push_back(trie[cur2][s[i]-'a']=++tot);
            cur2=trie[cur2][s[i]-'a'];
        }a[cur1].push_back(cur2);
    }
    for(int i=1;i<=q;++i){
        scanf(" %s %s",s,t);
        int m=strlen(s);
        int l=0;
        for(;s[l]==t[l];++l);
        int r=m-1;
        for(;s[r]==t[r];--r);
        u64 hx=0;
        for(int i=l;i<=r;++i)hx+=_key[(i-l)*2]*s[i]+_key[(i-l)*2+1]*t[i];
        int o;
        if(id.find(hx)!=id.end())o=id[hx];
        else continue;
        int cur1=root[o][0],cur2=root[o][1];
        for(int i=l;i--;){
            if(!trie[cur1][s[i]-'a'])break;
            cur1=trie[cur1][s[i]-'a'];
        }
        for(int i=r+1;i<m;++i){
            if(!trie[cur2][s[i]-'a'])break;
            cur2=trie[cur2][s[i]-'a'];
        }b[cur1].push_back(i),p[i]=cur2;
    }
    for(int i=1;i<=_tot;++i)dfs1(root[i][1]),dfs2(root[i][0]);
    for(int i=1;i<=q;++i)printf("%d\n",res[i]);
}
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    AfterTheRainStops::main();
    return 0;
}