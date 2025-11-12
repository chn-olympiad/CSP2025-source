#include<iostream>
#include<string>
using namespace std;

#define ll long long
const int maxn=2e5+10,mod1=998244353,mod2=1e9+7,base=27;
int n,q; pair<int,int> pre[maxn],suf[maxn],qpow[5000001];
struct simplified{ int prelen,suflen; pair<int,int> pre,suf,mid1,mid2; } ai[maxn];

pair<int,int> myhash(string s, int l, int r){
    pair<int,int> res={0,0};
    for(int i=l;i<r;i++){
        res.first=((ll)res.first*base+s[i]-'a'+1)%mod1;
        res.second=((ll)res.second*base+s[i]-'a'+1)%mod1;
    }
    return res;
}
simplified simplify(string s, string t){
    int pre=0,suf=s.size();
    while(pre<s.size()&&s[pre]==t[pre])pre++;
    while(suf>=1&&s[suf-1]==t[suf-1])suf--;
    return {pre, s.size()-suf, myhash(s,0,pre), myhash(s,suf,s.size()), myhash(s, pre, suf), myhash(t, pre, suf)};
}
bool is_prefix(string s, string t){
    if(s.size()>t.size())return false;
    for(int i=0;i<s.size();i++)if(s[i]!=t[i])return false;
    return true;
}
bool is_suffix(string s, string t){
    if(s.size()>t.size())return false;
    for(int i=0;i<s.size();i++)if(s[s.size()-i-1]!=t[t.size()-i-1])return false;
    return true;
}
int main(){
freopen("replace.in", "r", stdin);
freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s,t; cin>>s>>t;
        ai[i]=simplify(s,t);
    }
    qpow[0]={1,1};
    for(int i=1;i<=5000000;i++)qpow[i].first=(ll)qpow[i-1].first*base%mod1,qpow[i].second=(ll)qpow[i-1].second*base%mod2;
    while(q--){
         string s,t; cin>>s>>t;
         if(s.size()!=t.size()){
             cout<<0<<endl;
             continue;
         }
         auto r=simplify(s,t); int ans=0;
         suf[0]={0,0};
         for(int i=s.size()-r.suflen;i<s.size();i++){
             suf[i+r.suflen-s.size()+1].first=((ll)suf[i+r.suflen-s.size()].first*base+s[i]-'a'+1)%mod1;
             suf[i+r.suflen-s.size()+1].second=((ll)suf[i+r.suflen-s.size()].second*base+s[i]-'a'+1)%mod2;
         }
        pre[0]={0,0};
        for(int i=1;i<=r.prelen;i++){
            pre[i].first=((ll)qpow[i-1].first*(s[r.prelen-i]-'a'+1)+pre[i-1].first)%mod1;
            pre[i].second=((ll)qpow[i-1].second*(s[r.prelen-i]-'a'+1)+pre[i-1].second)%mod2;
        }
         for(int i=1;i<=n;i++)if(
             r.mid1==ai[i].mid1&&
             r.mid2==ai[i].mid2&&
             ai[i].suflen<=r.suflen&&
             ai[i].prelen<=r.prelen&&
             suf[ai[i].suflen]==ai[i].suf&&
             pre[ai[i].prelen]==ai[i].pre
             /*is_prefix(ai[i].suf, r.suf)&&is_suffix(ai[i].pre, r.pre)*/)ans++;
         cout<<ans<<endl;
    }
}