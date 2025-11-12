#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll db=1;
const ll inf=1e18;
void solve(ll n,ll q,vector<string>&s1,vector<string>&s2,vector<string>&t1,vector<string>&t2){
    map<string,string>m;
    for(ll i=1;i<=n;i++)m[s1[i]]=s2[i];
    for(ll i=1;i<=q;i++){
        if(t1[i].length()!=t2[i].length()){
            cout<<"0\n";
            continue;
        }
        ll ans=0;
        string f=t1[i],t=t2[i];
        for(ll l=0;l<f.length();l++){
            for(ll r=l;r<f.length();r++){
                string nf=f.substr(l,r-l+1),nt=t.substr(l,r-l+1),ff=f;
                if(m.count(nf)&&m[nf]==nt){
                    for(ll k=l;k<=r;k++)ff[k]=t[k];
                    if(ff==t)ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
void solve1(ll n,ll q,vector<string>&s1,vector<string>&s2,vector<string>&t1,vector<string>&t2){
    map<ll,vector<ll>>m;
    for(ll i=1;i<=n;i++){
        ll w1=0,w2=0;
        for(ll j=0;j<s1[i].length();j++)if(s1[i][j]=='b')w1=j;
        for(ll j=0;j<s2[i].length();j++)if(s2[i][j]=='b')w2=j;
        m[w1-w2].push_back(s1[i].length());
    }
    for(ll i=1;i<=q;i++){
        if(t1[i].length()!=t2[i].length()){
            cout<<"0\n";
            return;
        }
        ll w1=0,w2=0;
        for(ll j=0;j<t1[i].length();j++)if(t1[i][j]=='b')w1=j;
        for(ll j=0;j<t2[i].length();j++)if(t2[i][j]=='b')w2=j;
        ll ans=0;
        if(m.count(w1-w2)){
            ll w=upper_bound(m[w1-w2].begin(),m[w1-w2].end(),t1[i].length())-m[w1-w2].begin()-1;
            ans=max(0ll,w);
        }
        cout<<ans<<"\n";
    }
}
void solve2(ll n,ll q,vector<string>&s1,vector<string>&s2,vector<string>&t1,vector<string>&t2){
    ll ans=0;
    map<string,string>m;
    for(ll i=1;i<=n;i++){
        m[s1[i]]=m[s2[i]];
    }
    for(ll i=1;i<=q;i++){
        if(t1[i].length()!=t2[i].length()){
            cout<<"0\n";
            return;
        }
        ll ans=0;
        for(ll j=0;j<t1[i].length();j++){
                string tt="";tt+=t1[i][j];
                string ss="";ss+=t2[i][j];
            if(t1[i][j]!=t2[i][j])ans++;//=((m.count(tt))&&m[tt]==ss?)1:0);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    if(db&1)freopen("replace.in","r",stdin);
    if(db&1)freopen("replace.out","w",stdout);
    ll n,q;cin>>n>>q;
    ll L1=0,L2=0;
    vector<string>s1(n+1),s2(n+1);
    for(ll i=1;i<=n;i++)cin>>s1[i]>>s2[i],L1+=s1[i].length()+s2[i].length();
    vector<string>t1(q+1),t2(q+1);
    for(ll i=1;i<=q;i++)cin>>t1[i]>>t2[i],L2+=t1[i].length()+t2[i].length();
    if(L1<=2000&&L2<=2000){solve(n,q,s1,s2,t1,t2);return 0;}
    auto fp=[&](){
        map<char,ll>m;
        for(ll i=1;i<=n;i++){
            ll c=0;
            for(ll j=0;j<s1[i].length();j++){m[s1[i][j]]++;if(s1[i][j]=='b')c++;}
            if(c!=1)return 0;
            c=0;
            for(ll j=0;j<s2[i].length();j++){m[s2[i][j]]++;if(s2[i][j]=='b')c++;}
            if(c!=1)return 0;
        }
        for(ll i=1;i<=q;i++){
            ll c=0;
            for(ll j=0;j<t1[i].length();j++){m[t1[i][j]]++;if(t1[i][j]=='b')c++;}
            if(c!=1)return 0;
            c=0;
            for(ll j=0;j<t2[i].length();j++){m[t2[i][j]]++;if(t2[i][j]=='b')c++;}
            if(c!=1)return 0;
        }
        if(m.size()==2&&m.count('a')&&m.count('b'))return 1;
        return 0;
    };
    if(fp())solve1(n,q,s1,s2,t1,t2);
    else solve2(n,q,s1,s2,t1,t2);
    return 0;
}
