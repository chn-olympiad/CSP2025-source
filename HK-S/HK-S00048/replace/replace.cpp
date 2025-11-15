#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=5e6+6;
ll n, q, fst, lst, ans, aa, bb;
string s1, s2, t1, t2;
map<pair<string,string>, pair<ll, ll>> mp;
struct AC{
    struct Node{
        int son[26];
        ll fail, cnt;
    }tr[MAXN];
    vector<ll> e[MAXN];
    ll tot;
    ll NewRoot(){
        return ++tot;
    }
    ll New(){
        return ++tot;
    }
    void Insert(ll rt, string s){
        for(ll i=0; i<s.length(); i++){
            if(!tr[rt].son[s[i]-'a']){
                tr[rt].son[s[i]-'a']=New();
            }
            rt=tr[rt].son[s[i]-'a'];
        }
        tr[rt].cnt++;
    }
    void dfs(ll x, ll y){
        y+=tr[x].cnt;
        tr[x].cnt=y;
        for(ll i=0; i<e[x].size(); i++){
            dfs(e[x][i],y);
        }
    }
    void Cal(ll rt){
        queue<ll> q;
        tr[rt].fail=rt;
        for(ll i=0; i<26; i++){
            if(tr[rt].son[i]){
                tr[tr[rt].son[i]].fail=rt;
                e[rt].push_back(tr[rt].son[i]);
                q.push(tr[rt].son[i]);
            }
            else{
                tr[rt].son[i]=rt;
            }
        }
        ll x;
        while(q.size()){
            x=q.front();
            q.pop();
            for(ll i=0; i<26; i++){
                if(tr[x].son[i]){
                    tr[tr[x].son[i]].fail=tr[tr[x].fail].son[i];
                    e[tr[tr[x].fail].son[i]].push_back(tr[x].son[i]);
                    q.push(tr[x].son[i]);
                }
                else{
                    tr[x].son[i]=tr[tr[x].fail].son[i];
                }
            }
        }
        dfs(rt,0);
    }
    ll Solve(ll rt, string s){
        ll res=0;
        for(ll i=0; i<s.length(); i++){
            rt=tr[rt].son[s[i]-'a'];
            res+=tr[rt].cnt;
        }
        return res;
    }
}ac;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>q;
    for(ll i=1; i<=n; i++){
        cin>>s1>>s2;
        fst=lst=-1;
        for(ll j=0; j<s1.size(); j++){
            if(s1[j]!=s2[j]){
                if(fst==-1){
                    fst=j;
                }
                lst=j;
            }
        }
        if(fst!=-1){
            t1=t2="";
            for(ll j=fst; j<=lst; j++){
                t1+=s1[j];
                t2+=s2[j];
            }
            if(mp.find(make_pair(t1,t2))==mp.end()){
                mp[make_pair(t1,t2)]=make_pair(ac.NewRoot(),ac.NewRoot());
            }
            ac.Insert(mp[make_pair(t1,t2)].first,s1);
            reverse(s1.begin(), s1.end());
            ac.Insert(mp[make_pair(t1,t2)].second,s1);
        }
    }
    for(map<pair<string,string>,pair<ll,ll>>::iterator it=mp.begin(); it!=mp.end(); it++){
        ac.Cal(it->second.first);
        ac.Cal(it->second.second);
    }
    while(q--){
        cin>>s1>>s2;
        fst=lst=-1;
        for(ll j=0; j<s1.size(); j++){
            if(s1[j]!=s2[j]){
                if(fst==-1){
                    fst=j;
                }
                lst=j;
            }
        }
        t1=t2="";
        for(ll j=fst; j<=lst; j++){
            t1+=s1[j];
            t2+=s2[j];
        }
        ans=0;
        if(mp.find(make_pair(t1,t2))!=mp.end()){
            aa=mp[make_pair(t1,t2)].first;
            bb=mp[make_pair(t1,t2)].second;
            ans+=ac.Solve(aa,s1);
            t1=t2="";
            for(ll i=0; i<lst; i++){
                t1+=s1[i];
            }
            ans-=ac.Solve(aa,t1);
            for(ll i=s1.length()-1; i>fst; i--){
                t2+=s1[i];
            }
            ans-=ac.Solve(bb,t2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}