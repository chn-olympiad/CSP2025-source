#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<string,pair<int,int> > gt(string x,string y){
    int l,r;
    l=0,r=x.size()-1;
    while(l<=r&&x[l]==y[l]){
        ++l;
    }
    while(l<=r&&x[r]==y[r]){
        --r;
    }
    if(r<l){
        return {"",{l,r}};
    }
    string ans;
    ans="";
    for(int i=l;i<=r;i++){
        ans+=x[i];
        ans+=y[i];
    }
    return {ans,{l,r}};
}
map<string,int> root;
int trie[5000009][27];
long long sm[5000009];
int nxt[5000009];
int fa[5000009];
int inn;
inline void dfs(int t,int z){
    if(fa[t]==0){
        nxt[t]=t;
    }else{
        nxt[t]=trie[nxt[fa[t]]][z];
    }
    sm[t]+=sm[nxt[t]];
    for(int i=0;i<27;i++){
        if(!trie[t][i]){
            trie[t][i]=trie[nxt[t]][i];
        }
    }
    for(int i=0;i<27;i++){
        if(trie[t][i]){
            dfs(trie[t][i],i);
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string xs,ys;
        cin>>xs>>ys;
        pair<string,pair<int,int> > cc;
        cc=gt(xs,ys);
        string xx;int l,r;
        xx=cc.first,l=cc.second.first,r=cc.second.second;
        if(xx==""){
            continue;
        }
        int x;
        if(root[xx]){
            x=root[xx];
        }else{
            ++inn;
            fa[inn]=0;
            root[xx]=inn;
            x=inn;
        }
        string zz;
        zz="";
        for(int i=0;i<l;i++){
            zz+=xs[i];
        }
        zz+=char('z'+1);
        for(int i=r+1;i<xs.size();i++){
            zz+=xs[i];
        }

        for(int i=0;i<zz.size();i++){
            if(!trie[x][zz[i]-'a']){
                trie[x][zz[i]-'a']=++inn;
                fa[inn]=x;
            }
            x=trie[x][zz[i]-'a'];
        }
        sm[x]++;
    }
    for(int i=1;i<=inn;i++){
        if(fa[i]==0){
            dfs(i,0);
        }
    }
    //q=10;
    while(q--){
        string xs,ys;
        cin>>xs>>ys;
        pair<string,pair<int,int> > cc;
        cc=gt(xs,ys);
        string xx;int l,r;
        xx=cc.first,l=cc.second.first,r=cc.second.second;
        if(xx==""){
            cout<<0<<endl;
            continue;
        }
        int x;
        if(root[xx]){
            x=root[xx];
        }else{
            cout<<0<<endl;
            continue;
        }
        string zz;
        zz="";
        for(int i=0;i<l;i++){
            zz+=xs[i];
        }
        zz+=char('z'+1);
        for(int i=r+1;i<xs.size();i++){
            zz+=xs[i];
        }
        long long ans;
        ans=0;
        for(int i=0;i<zz.size();i++){
            x=trie[x][zz[i]-'a'];
            ans+=sm[x];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
