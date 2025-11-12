#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=2e5+10;
string s1,s2;
int n,q;
ll p[30];
map<pair<ll,ll>,int>a;
ll sum(string &x,int u,int v){
    ll s=1;
    for(int i=u;i<=v;i++)
        s=s*p[x[i]-'a']*131;
    return s;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    srand(time(0));
    for(int i=1;i<=26;i++)p[i]=rand()*rand()*rand()*rand()*rand()*rand()*(1e9+7);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        int st,en,j;
        for(j=0;j<s1.size();j++){
            if(s1[j]!=s2[j]){
                st=j;
                break;
            }
        }
        if(j==s1.size()){
            ll x=sum(s1,0,s1.size()),y=sum(s2,0,s2.size());
            pair<ll,ll>t;
            t.first=x;t.second=y;
            a[t]++;
            continue;
        }
        for(j=s1.size()-1;j>=0;j--)
        if(s1[j]!=s2[j]){
            en=j;
            break;
        }
        ll x=sum(s1,st,en),y=sum(s2,st,en);
        //cout<<x<<' '<<y<<'\n';
        pair<ll,ll>t;
        t.first=x;t.second=y;
        a[t]++;
    }
    while(q--){
        string u,v;
        cin>>u>>v;
        if(u.size()!=v.size()){
            cout<<0<<'\n';
            continue;
        }
        int st=0,en=u.size(),j;
        for(j=0;j<u.size();j++){
            if(u[j]!=v[j]){
                st=j;
                break;
            }
        }
        if(j!=u.size()){
            for(j=u.size()-1;j>=0;j--)
                if(u[j]!=v[j]){
                    en=j;
                    break;
                }
        }
        ll x=sum(u,st,en),y=sum(v,st,en);
        //cout<<st<<' '<<en<<'\n';
        pair<ll,ll>t;
        t.first=x;t.second=y;
        cout<<a[t]<<'\n';
    }
    return 0;
}
/*
54542910576 56201939640
17292 17822
17556 18090
17161 17424
54542910576 56201939640
0
294499921 303595776
0
*/
