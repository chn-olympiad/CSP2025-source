#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;
int n,q,lens[202020],lent[202020],cnt;
long long p = 31,mod = 1e9+7;
string s[202020][2],t[202020][2];
map<pair<int,int>,int> hshToId;
long long Hash(string str,int a,int b){
    long long res = 0;
    for(int i = a;i<=b;i++) res = ((res*p)%mod+str[i]-'a'+1)%mod;
    return res;
}int cnt1 = 1,cnt2 = 1,son1[5050505][26],son2[5050505][26];
vector<int> ids1[5050505],ids2[5050505];
void add1(int u,string s,int id,int ind){
    for(int i = id;i>=0;i--){
        if(!son1[u][s[i]-'a']) son1[u][s[i]-'a'] = ++cnt1;
        u = son1[u][s[i]-'a'];
    }ids1[u].push_back(ind);
}void add2(int u,string s,int id,int ind){
    for(int i = id;i<s.length();i++){
        if(!son2[u][s[i]-'a']) son2[u][s[i]-'a'] = ++cnt2;
        u = son2[u][s[i]-'a'];
    }ids2[u].push_back(ind);
}int check1(int u,string s,int id){
    for(int i = id;i>=0;i--){
        if(!son1[u][s[i]-'a']) return u;
        u = son1[u][s[i]-'a'];
    }return u;
}int check2(int u,string s,int id){
    for(int i = id;i<s.length();i++){
        if(!son2[u][s[i]-'a']) return u;
        u = son2[u][s[i]-'a'];
    }return u;
}int son[5050505],siz[5050505],dfn[5050505],top[5050505],t,point[5050505];
void dfs1(int u){
    siz[u] = 1;
    for(int i = 0;i<26;i++){
        if(!son2[u][i]) continue;
        dfs1(son2[u][i]);
        siz[u] += siz[son2[u][i]];
        if(siz[son2[u][i]]>siz[son[u]]) son[u] = son2[u][i];
    }
}void dfs2(int u){
    dfn[u] = ++t;
    for(int i = 0;i<ids2[u].size();i++) point[ids2[u][i]] = dfn[u];
    if(!son[u]) continue;
    top[son[u]] = top[u];
    dfs2(son[u]);
    for(int i = 0;i<26;i++){
        int v = son2[u][i];
        if(!v || v==son[u]) continue;
        top[v] = v;
        dfs2(v);
    }
}struct que{int i,id1,id2;};
vector<que> qs[5050505],qqs[5050505];
long long ans[202020];
long long sum[]
void dfs(int u){
    for(int i = 0;i<ids1[u].size();i++) change(1,1,cnt2,point[ids1[u][i]],1);
    for(int i = 0;i<qqs[u].size();i++) ans[qqs[u][i].i] = queryT(id2);
    for(int i = 0;i<26;i++){
        int v = son1[u][i];
        if(!v) continue;
        dfs(v);
    }for(int i = 0;i<ids1[u].size();i++) change(1,1,cnt2,point[ids1[u][i]],-1);
}void solve(int hshr){
    for(int i = 0;i<qs[hshr].size();i++) while(qqs[qs[hshr][i].id1].size()) qqs[qs[hshr][i].id1].pop_back();
    for(int i = 0;i<qs[hshr].size();i++) qqs[qs[hshr][i].id1].push_back(qs[hshr][i]);
    dfs(rt1[hshr]);
}
int main(){
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> s[i][0] >> s[i][1];
        int sr = 0,ed = (lens[i]=s[i][0].length())-1;
        while(s[i][0][sr]==s[i][1][sr]) sr++;
        while(s[i][0][ed]==s[i][1][ed]) ed--;
        int hsh1 = Hash(s[i][0],sr,ed),hsh2 = Hash(s[i][1],sr,ed);
        pair<int,int> pir = make_pair(hsh1,hsh2);
        if(!hshToId[pir]) hshToId[pir] = ++cnt,rt1[pir] = ++cnt1,rt2[pir] = ++cnt2;
        add1(rt1[pir],s[i][0],sr-1,i);add2(rt2[pir],s[i][0],ed+1,i);
    }for(int i = 1;i<=q;i++){
        cin >> t[i][0] >> t[i][1];
        int sr = 0,ed = (lent[i]=t[i][0].length())-1;
        while(t[i][0][sr]==t[i][1][sr]) sr++;
        while(t[i][0][ed]==t[i][1][ed]) ed--;
        int pir = hshToId[make_pair(hsh1,hsh2);
        int hsh1 = Hash(t[i][0],sr,ed),hsh2 = Hash(t[i][1],sr,ed);
        int id1 = check1(pir,t[i][0],sr-1),id2 = check2(pir,t[i][0],ed+1);
        qs[pir].push_back((que){i,id1,id2});
    }for(int i = 1;i<=cnt;i++) solve(i);
    for(int i = 1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
