#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define mk make_pair
#define lc x<<1
#define rc x<<1|1
#define N 205050
#define M 5000500
int ch[M][26],n,m,fail[M],num,rt,dep[M],ed[M],sta[M],top,c[M],ans[N],q;
vector<pr >ask[M];
vector<int>e[M];
void ins(string s){
    int p=rt;
    for(int i=0;i<s.size();++i){
        int x=s[i]-'a';
        if(!ch[p][x])ch[p][x]=++num,dep[num]=i+1;
        p=ch[p][x];
    }
    // cout<<"ins "<<s<<" "<<p<<"\n";
    ed[p]++;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;++i)if(ch[rt][i])q.push(ch[rt][i]),e[0].push_back(ch[rt][i]);
    while(!q.empty()){
        int p=q.front();q.pop();
        // cerr<<p<<"\n";
        for(int i=0;i<26;++i){
            if(ch[p][i])fail[ch[p][i]]=ch[fail[p]][i],q.push(ch[p][i]),e[fail[ch[p][i]]].push_back(ch[p][i]);
            else ch[p][i]=ch[fail[p]][i];
        }
    }
}
void calc(string s,int id,int l,int r){
    int p=rt;
    // cout<<id<<" "<<l<<" "<<r<<"\n";    
    for(int i=0;i<s.size();++i){
        int x=s[i]-'a';
        p=ch[p][x];
        if(i>=r&&(i&1)){
            ask[p].emplace_back(id,i-l+1);
        }
    }
}
void sol(int x){
    // cerr<<x<<"\n";
    if(ed[x])sta[++top]=dep[x],c[top]=ed[x]+c[top-1];
    for(auto to:ask[x]){
        int l=to.second;
        int p=lower_bound(sta+1,sta+top+1,l)-sta;
        ans[to.first]+=c[top]-c[p-1];
    }
    for(auto y:e[x])sol(y);
    if(ed[x])--top;
}
signed main(){
    clock_t st=clock();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;++i){
        string x,y;cin>>x>>y;
        string now="";
        for(int j=0;j<x.size();++j)now.push_back(x[j]),now.push_back(y[j]);
        ins(now);
    }build();
    for(int i=0;i<q;++i){
        string x,y,now="";
        cin>>x>>y;
        int l=-1,r=-1;
        if(x.size()!=y.size())continue;
        for(int j=0;j<x.size();++j)now.push_back(x[j]),now.push_back(y[j]);
        for(int j=0;j<x.size();++j)if(x[j]!=y[j]){l=j<<1;break;}
        for(int j=x.size()-1;~j;--j)if(x[j]!=y[j]){r=j<<1|1;break;}
        if(l==-1)l=0,r=0;
        calc(now,i,l,r);
    }
    sol(0);
    for(int i=0;i<q;++i)cout<<ans[i]<<"\n";
    cerr<<fixed<<setprecision(10)<<(double)(clock()-st)/CLOCKS_PER_SEC<<"\n";
}