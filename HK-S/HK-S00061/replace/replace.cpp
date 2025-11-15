#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    map<pair<int,int> >ch; int fail=0; int endings=0; int dep=0;
    int fa; pair<int,int>tp;
};
ll ans[200005];
struct Automaton{
    node nd[2500002];
    vector<pair<int,int> >qrs[2500002];
    ll timer=1;
    void add_string(string s, string t){
        ll cur=0;
        for(int i=0;i<s.length();i++){
            if(!nd[cur].ch[{s[i]-'a',t[i]-'a'}]){
                nd[cur].ch[{s[i]-'a',t[i]-'a'}]=timer++,nd[nd[cur].ch[{s[i]-'a',t[i]-'a'}]].dep=nd[cur].dep+1;
                nd[timer-1].fa=cur; nd[timer-1].tp={s[i]-'a',t[i]-'a'};
            }
            cur=nd[cur].ch[{s[i]-'a',t[i]-'a'}];
        }
        nd[cur].endings++;
    }
    vector<int>bucks[2500002];
    void pre(){
        for(int i=1;i<=timer-1;i++){
            bucks[nd[i].dep].push_back(i);
        }
        for(int i=0;i<=2500000;i++){
            for(auto& u: bucks[i]){
                nd[u].fail=nd[nd[u].fa].fail;
                while(nd[u].fail){
                    if(nd[nd[u].fail].ch[nd[u].tp])nd[u].fail=nd[nd[u].fail].ch[nd[u].tp];
                    else nd[u].fail=nd[nd[u].fail].fail;
                }
                if(!nd[u].fail){
                    if(nd[0].ch[nd[u].tp])nd[u].fail=nd[0].ch[nd[u].tp];
                }
                adj[nd[u].fail].push_back(u);
                // nd[u].endings+=nd[nd[u].fail].endings;
            }
        }
    }
    void qry(sting s, string t, ll which){
        ll ans=0;
        ll cur=0;
        ll lst,frt;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i])lst=i;
        }
        for(int i=(int)s.length()-1;i>=0;i--){
            if(s[i]!=t[i])frt=i;
        }
        for(int i=0;i<(int)s.length();i++){
            pair<ll,ll> tp={s[i]-'a',t[i]-'a'};
            while(cur){
                if(nd[cur].ch[tp]){cur=nd[cur].ch[tp]; break;}
                else{
                    cur=nd[cur].fail;
                }
            }
            if(!cur){
                if(nd[cur].ch[tp])cur=nd[cur].ch[tp];
            }
            if(i<lst)continue;
            qrs[cur].push_back({which,i-frt+1});
        }
    }
    vector<int>adj[2500001];
    vector<int>listt; bool vis[2500001];
    void dfs(int s){
        if(nd[s].endings){
            for(int i=1;i<=nd[s].endings;i++){
                listt.push_back(nd[s].dep);
            }
        }
        for(auto& u: adj[s]){
            if(!vis[u]){
                dfs(u);
            }
        }
        if(listt.size()==0)return;
        for(auto& [qid,mind]: qrs[s]){
            ll l=0,r=listt.size()-1;
            if(listt[r]<mind)continue;
            while(l<r){
                ll mid=(l+r)>>1;
                if(listt[mid]>=mind)r=mid;
                else l=mid+1;
            }
            ans[qid]+=listt.size()-l;
        }
    }
}ac;
void solve(){
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,t;
        cin>>s>>t;
        ac.add_string(s,t);
    }
    ac.pre();
    for(int i=1;i<=q;i++){
        string s,t;
        cin>>s>>t;
        if(s.length()!=t.length()){
            ans[i]=0;
        }
        else{
            ac.qry(s,t,i);
        }
    }
    ac.dfs(0);
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<'\n';
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--)solve();   
}

/*
    g++ -std=c++2a -O2 replace.cpp -o replace && ./replace
*/