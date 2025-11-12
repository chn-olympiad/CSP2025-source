#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 10000001
#define mod 998244353
#define P 131

struct node{
    string pre,suf;
    ll a,b;
};

ll n,q,cnt;
ll h1[SIZE],h2[SIZE];
vector<node> f[SIZE];
map<pair<ll,ll>,ll> p;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        string s1,s2,pre,suf;
        cin>>s1>>s2;
        ll j=0,s=0,t=0;
        for(;j<s1.size()&&s1[j]==s2[j];j++) pre=s1[j]+pre;
        for(;j<s1.size()&&s1.back()==s2.back();s1.pop_back(),s2.pop_back()) suf=s1.back()+suf;
        for(;j<s1.size();j++){
            s=(s*P+s1[j])%mod;
            t=(t*P+s2[j])%mod;
        }
        ll a=0,b=0;
        for(j=0;j<pre.size();j++)
        a=(a*P+pre[j])%mod;
        for(j=0;j<suf.size();j++)
        b=(b*P+suf[j])%mod;
        if(!p[{s,t}]) p[{s,t}]=++cnt;
        ll x=p[{s,t}];
        f[x].push_back({pre,suf,a,b});
    }
    while(q--){
        string s1,s2,pre,suf;
        cin>>s1>>s2;
        ll j=0,s=0,t=0;
        for(;s1[j]==s2[j];j++) pre=s1[j]+pre;
        for(;s1.back()==s2.back();s1.pop_back(),s2.pop_back()) suf=s1.back()+suf;
        for(;j<s1.size();j++){
            s=(s*P+s1[j])%mod;
            t=(t*P+s2[j])%mod;
        }
        for(j=0;j<pre.size();j++)
        h1[j+1]=(h1[j]*P+pre[j])%mod;
        for(j=0;j<suf.size();j++)
        h2[j+1]=(h2[j]*P+suf[j])%mod;
        ll x=p[{s,t}];
        if(!x){cout<<"0\n";continue;}
        ll res=0;
        for(ll i=0;i<f[x].size();i++){
            ll ls=f[x][i].pre.size(),lt=f[x][i].suf.size();
            if(ls>pre.size()||lt>suf.size()) continue;
            if(h1[ls]==f[x][i].a&&h2[lt]==f[x][i].b) res++;
        }        
        cout<<res<<'\n';
    }
    return 0;
}