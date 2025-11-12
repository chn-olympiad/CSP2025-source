#include <bits/stdc++.h>
using namespace std;
struct rep{
    string fi,se,di;
    pair<int,int> workdi(){
        int st,ed;
        for(int i=0;i<fi.size();i++)
            if(fi[i]!=se[i]) ed=i, st=min(st,i);
        for(int i=st;i<=ed;i++) di+=fi[i],di+=se[i];
        return {st,ed};
    }
};
struct trie{
    vector<int> tr[26];
    vector<int> endf;
    int newn(){
        for(int i=0;i<26;i++) tr[i].push_back(-1);
        endf.push_back(0);
        return tr[0].size()-1;
    }
    trie(){newn();};
    int insert(string s,int flag){
        int now=0;
        for(auto ch:s){
            if(tr[ch-'a'][now]==-1)
                tr[ch-'a'][now]=newn();
            now=tr[ch-'a'][now];
        }
        endf[now]=flag;
    }
    int find(string s){
        int now=0;
        for(auto ch:s){
            if(tr[ch-'a'][now]==-1)return -1;
            now=tr[ch-'a'][now];
        }return endf[now];
    }
};
trie d;
vector<vector<string>> sim1,sim2,sim3,sim4;
rep s[200005],t[200005];
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].fi>>s[i].se;
        auto tmp=s[i].workdi();
        int res=d.find(s[i].di);
        string tp;
        if(res<=0){
            res=sim1.size();
            d.insert(s[i].di,sim1.size());
            sim1.resize(sim1.size()+1);
            sim2.resize(sim2.size()+1);
            sim3.resize(sim3.size()+1);
            sim4.resize(sim4.size()+1);
        }
        tp=s[i].fi.substr(0,tmp.first);
        reverse(tp.begin(),tp.end());
        sim1[res].push_back(tp);
        tp=s[i].fi.substr(tmp.second+1);
        sim2[res].push_back(tp);
        tp=s[i].se.substr(0,tmp.first);
        reverse(tp.begin(),tp.end());
        sim3[res].push_back(tp);
        tp=s[i].se.substr(tmp.second+1);
        sim4[res].push_back(tp);
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].fi>>t[i].se;
        t[i].workdi();
        int res=d.find(t[i].fi);
        if(res<=0) {cout<<0<<'\n';continue;}
        else cout<<res<<'\n';
    }
    return 0;
}
